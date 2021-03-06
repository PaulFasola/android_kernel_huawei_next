/*
 * Generic big.LITTLE CPUFreq Interface driver
 *
 * It provides necessary ops to arm_big_little cpufreq driver and gets
 * Frequency information from Device Tree. Freq table in DT must be in KHz.
 *
 * Copyright (C) 2013 Linaro.
 * Viresh Kumar <viresh.kumar@linaro.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed "as is" WITHOUT ANY WARRANTY of any
 * kind, whether express or implied; without even the implied warranty
 * of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#define pr_fmt(fmt) KBUILD_MODNAME ": " fmt

#include <linux/cpu.h>
#include <linux/cpufreq.h>
#include <linux/device.h>
#include <linux/export.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/opp.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/types.h>
#include "arm_big_little.h"

/* get cpu node with valid operating-points */
static struct device_node *get_cpu_node_with_valid_op(int cpu)
{
	struct device_node *np = NULL, *parent;
	int count = 0;

	parent = of_find_node_by_path("/cpus");
	if (!parent) {
		pr_err("failed to find OF /cpus\n");
		return NULL;
	}

	for_each_child_of_node(parent, np) {
		if (count++ != cpu)
			continue;
		if (!of_get_property(np, "operating-points", NULL)) {
			of_node_put(np);
			np = NULL;
		}

		break;
	}

	of_node_put(parent);
	return np;
}

#ifdef CONFIG_HISI_CPUFREQ
/* get cpu node with no operating-points check */
static struct device_node *get_cpu_node(int cpu)
{
	struct device_node *np = NULL, *parent;
	int count = 0;

	parent = of_find_node_by_path("/cpus");
	if (!parent) {
		pr_err("failed to find OF /cpus\n");
		return NULL;
	}

	for_each_child_of_node(parent, np) {
		if (count++ == cpu)
			break;
	}

	of_node_put(parent);
	return np;
}
#endif

static int dt_init_opp_table(struct device *cpu_dev)
{
	struct device_node *np;
	int ret;

	np = get_cpu_node_with_valid_op(cpu_dev->id);
	if (!np)
		return -ENODATA;

	cpu_dev->of_node = np;
	ret = of_init_opp_table(cpu_dev);
	of_node_put(np);

	return ret;
}

static int dt_get_transition_latency(struct device *cpu_dev)
{
	struct device_node *np;
	u32 transition_latency = CPUFREQ_ETERNAL;

    /* if policy->cpu was hotplugged early before suspend, policy->cpu
     * was transferred to next cpu, in the resume path, the new policy->cpu
     * get transition latency fail because it has no operating-points in the dts,
     * result in restore governor fail, so we do not check the operating-points
     * when get transition latency
     */
#ifdef CONFIG_HISI_CPUFREQ
    np = get_cpu_node(cpu_dev->id);
#else
	np = get_cpu_node_with_valid_op(cpu_dev->id);
#endif
	if (!np)
		return CPUFREQ_ETERNAL;

	of_property_read_u32(np, "clock-latency", &transition_latency);
	of_node_put(np);

	pr_debug("%s: clock-latency: %d\n", __func__, transition_latency);
	return transition_latency;
}

static struct cpufreq_arm_bL_ops dt_bL_ops = {
	.name	= "dt-bl",
	.get_transition_latency = dt_get_transition_latency,
	.init_opp_table = dt_init_opp_table,
};

static int generic_bL_probe(struct platform_device *pdev)
{
	struct device_node *np;

	np = get_cpu_node_with_valid_op(0);
	if (!np)
		return -ENODEV;

	of_node_put(np);
	return bL_cpufreq_register(&dt_bL_ops);
}

static int generic_bL_remove(struct platform_device *pdev)
{
	bL_cpufreq_unregister(&dt_bL_ops);
	return 0;
}

#ifdef CONFIG_OF
static const struct of_device_id generic_bL_cpufreq[] = {
	{ .compatible = "arm,generic-bL-cpufreq" },
	{},
};
MODULE_DEVICE_TABLE(of, generic_bL_cpufreq);
#endif

static struct platform_driver generic_bL_platdrv = {
	.driver = {
		.name	= "arm-bL-cpufreq-dt",
		.owner	= THIS_MODULE,
#ifdef CONFIG_OF
		.of_match_table = of_match_ptr(generic_bL_cpufreq),
#endif
	},
	.probe		= generic_bL_probe,
	.remove		= generic_bL_remove,
};
module_platform_driver(generic_bL_platdrv);

MODULE_AUTHOR("Viresh Kumar <viresh.kumar@linaro.org>");
MODULE_DESCRIPTION("Generic ARM big LITTLE cpufreq driver via DT");
MODULE_LICENSE("GPL");

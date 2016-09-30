cmd_scripts/mod/devicetable-offsets.s :=   gcc -Wp,-MD,scripts/mod/.devicetable-offsets.s.d  -nostdinc -isystem /usr/lib/gcc/x86_64-linux-gnu/5/include -I/home/paul/Desktop/kernel/arch/x86/include -Iarch/x86/include/generated  -Iinclude -I/home/paul/Desktop/kernel/arch/x86/include/uapi -Iarch/x86/include/generated/uapi -I/home/paul/Desktop/kernel/include/uapi -Iinclude/generated/uapi -include /home/paul/Desktop/kernel/include/linux/kconfig.h -I/home/paul/Desktop/kernel/../vendor/hisi/modem/include/taf/ -I/home/paul/Desktop/kernel/../kernel/drivers/vendor/hisi/modem/include/taf -I/home/paul/Desktop/kernel/../kernel/drivers/vendor/hisi/ap/platform/hi3650 -I/home/paul/Desktop/kernel/../kernel/drivers/vendor/hisi/audiodsp/include/ap/med -I/home/paul/Desktop/kernel/../kernel/drivers/vendor/hisi/modem/include/taf -I/home/paul/Desktop/kernel/../kernel/drivers/vendor/hisi/ap/platform/hi3650 -I/home/paul/Desktop/kernel/../kernel/drivers/vendor/hisi/audiodsp/include/ap/med -D__KERNEL__ -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Wimplicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -DFEATURE_ON=1 -DFEATURE_OFF=0 -DBSP_CORE_APP -DBSP_COMPILE_ALLY -O2 -g -m64 -mno-mmx -mno-sse -mpreferred-stack-boundary=3 -mtune=generic -mno-red-zone -mcmodel=kernel -funit-at-a-time -maccumulate-outgoing-args -fstack-protector -DCONFIG_X86_X32_ABI -DCONFIG_AS_CFI=1 -DCONFIG_AS_CFI_SIGNAL_FRAME=1 -DCONFIG_AS_CFI_SECTIONS=1 -DCONFIG_AS_FXSAVEQ=1 -DCONFIG_AS_AVX=1 -DCONFIG_AS_AVX2=1 -pipe -Wno-sign-compare -fno-asynchronous-unwind-tables -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -Wframe-larger-than=1024 -Wno-unused-but-set-variable -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-var-tracking-assignments -g -pg -mfentry -DCC_USING_FENTRY -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO    -DBSP_CORE_APP -DBSP_COMPILE_ALLY -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(devicetable_offsets)"  -D"KBUILD_MODNAME=KBUILD_STR(devicetable_offsets)" -fverbose-asm -S -o scripts/mod/devicetable-offsets.s scripts/mod/devicetable-offsets.c

source_scripts/mod/devicetable-offsets.s := scripts/mod/devicetable-offsets.c

deps_scripts/mod/devicetable-offsets.s := \
  include/linux/kbuild.h \
  include/linux/mod_devicetable.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  include/uapi/linux/types.h \
  /home/paul/Desktop/kernel/arch/x86/include/uapi/asm/types.h \
  /home/paul/Desktop/kernel/include/uapi/asm-generic/types.h \
  include/asm-generic/int-ll64.h \
  include/uapi/asm-generic/int-ll64.h \
  /home/paul/Desktop/kernel/arch/x86/include/uapi/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/uapi/asm-generic/bitsperlong.h \
  /home/paul/Desktop/kernel/include/uapi/linux/posix_types.h \
  include/linux/stddef.h \
  include/uapi/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/kprobes.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
  include/linux/compiler-gcc5.h \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  /home/paul/Desktop/kernel/arch/x86/include/asm/posix_types.h \
    $(wildcard include/config/x86/32.h) \
  /home/paul/Desktop/kernel/arch/x86/include/uapi/asm/posix_types_64.h \
  /home/paul/Desktop/kernel/include/uapi/asm-generic/posix_types.h \
  include/linux/uuid.h \
  include/uapi/linux/uuid.h \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /usr/lib/gcc/x86_64-linux-gnu/5/include/stdarg.h \
  include/uapi/linux/string.h \
  /home/paul/Desktop/kernel/arch/x86/include/asm/string.h \
  /home/paul/Desktop/kernel/arch/x86/include/asm/string_64.h \
    $(wildcard include/config/kmemcheck.h) \

scripts/mod/devicetable-offsets.s: $(deps_scripts/mod/devicetable-offsets.s)

$(deps_scripts/mod/devicetable-offsets.s):

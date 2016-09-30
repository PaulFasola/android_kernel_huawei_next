	.file	"bounds.c"
# GNU C11 (Ubuntu 5.4.0-6ubuntu1~16.04.2) version 5.4.0 20160609 (x86_64-linux-gnu)
#	compiled by GNU C version 5.4.0 20160609, GMP version 6.1.0, MPFR version 3.1.4, MPC version 1.0.3
# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed:  -nostdinc -I /home/paul/Desktop/kernel/arch/x86/include
# -I arch/x86/include/generated -I include
# -I /home/paul/Desktop/kernel/arch/x86/include/uapi
# -I arch/x86/include/generated/uapi
# -I /home/paul/Desktop/kernel/include/uapi -I include/generated/uapi
# -I /home/paul/Desktop/kernel/../vendor/hisi/modem/include/taf/
# -I /home/paul/Desktop/kernel/../kernel/drivers/vendor/hisi/modem/include/taf
# -I /home/paul/Desktop/kernel/../kernel/drivers/vendor/hisi/ap/platform/hi3650
# -I /home/paul/Desktop/kernel/../kernel/drivers/vendor/hisi/audiodsp/include/ap/med
# -I /home/paul/Desktop/kernel/../kernel/drivers/vendor/hisi/modem/include/taf
# -I /home/paul/Desktop/kernel/../kernel/drivers/vendor/hisi/ap/platform/hi3650
# -I /home/paul/Desktop/kernel/../kernel/drivers/vendor/hisi/audiodsp/include/ap/med
# -imultiarch x86_64-linux-gnu -D __KERNEL__ -D FEATURE_ON=1
# -D FEATURE_OFF=0 -D BSP_CORE_APP -D BSP_COMPILE_ALLY
# -D CONFIG_X86_X32_ABI -D CONFIG_AS_CFI=1 -D CONFIG_AS_CFI_SIGNAL_FRAME=1
# -D CONFIG_AS_CFI_SECTIONS=1 -D CONFIG_AS_FXSAVEQ=1 -D CONFIG_AS_AVX=1
# -D CONFIG_AS_AVX2=1 -D CC_USING_FENTRY -D CC_HAVE_ASM_GOTO
# -D BSP_CORE_APP -D BSP_COMPILE_ALLY -D KBUILD_STR(s)=#s
# -D KBUILD_BASENAME=KBUILD_STR(bounds)
# -D KBUILD_MODNAME=KBUILD_STR(bounds)
# -isystem /usr/lib/gcc/x86_64-linux-gnu/5/include
# -include /home/paul/Desktop/kernel/include/linux/kconfig.h
# -MD kernel/.bounds.s.d kernel/bounds.c -m64 -mpreferred-stack-boundary=3
# -mtune=generic -mno-red-zone -mcmodel=kernel -maccumulate-outgoing-args
# -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -mfentry -march=x86-64
# -auxbase-strip kernel/bounds.s -g -g -O2 -Wall -Wundef
# -Wstrict-prototypes -Wno-trigraphs -Wimplicit-function-declaration
# -Wno-format-security -Wno-sign-compare -Wframe-larger-than=1024
# -Wno-unused-but-set-variable -Wdeclaration-after-statement
# -Wno-pointer-sign -p -fno-strict-aliasing -fno-common
# -fno-delete-null-pointer-checks -funit-at-a-time -fstack-protector
# -fno-asynchronous-unwind-tables -fno-omit-frame-pointer
# -fno-optimize-sibling-calls -fno-var-tracking-assignments
# -fno-strict-overflow -fconserve-stack -fverbose-asm
# options enabled:  -faggressive-loop-optimizations -falign-labels
# -fauto-inc-dec -fbranch-count-reg -fcaller-saves
# -fchkp-check-incomplete-type -fchkp-check-read -fchkp-check-write
# -fchkp-instrument-calls -fchkp-narrow-bounds -fchkp-optimize
# -fchkp-store-bounds -fchkp-use-static-bounds
# -fchkp-use-static-const-bounds -fchkp-use-wrappers
# -fcombine-stack-adjustments -fcompare-elim -fcprop-registers
# -fcrossjumping -fcse-follow-jumps -fdefer-pop -fdevirtualize
# -fdevirtualize-speculatively -fdwarf2-cfi-asm -fearly-inlining
# -feliminate-unused-debug-types -fexpensive-optimizations
# -fforward-propagate -ffunction-cse -fgcse -fgcse-lm -fgnu-runtime
# -fgnu-unique -fguess-branch-probability -fhoist-adjacent-loads -fident
# -fif-conversion -fif-conversion2 -findirect-inlining -finline
# -finline-atomics -finline-functions-called-once -finline-small-functions
# -fipa-cp -fipa-cp-alignment -fipa-icf -fipa-icf-functions
# -fipa-icf-variables -fipa-profile -fipa-pure-const -fipa-reference
# -fipa-sra -fira-hoist-pressure -fira-share-save-slots
# -fira-share-spill-slots -fisolate-erroneous-paths-dereference -fivopts
# -fkeep-static-consts -fleading-underscore -flifetime-dse -flra-remat
# -flto-odr-type-merging -fmath-errno -fmerge-constants
# -fmerge-debug-strings -fmove-loop-invariants -foptimize-strlen
# -fpartial-inlining -fpeephole -fpeephole2 -fprefetch-loop-arrays
# -fprofile -free -freg-struct-return -freorder-blocks
# -freorder-blocks-and-partition -freorder-functions -frerun-cse-after-loop
# -fsched-critical-path-heuristic -fsched-dep-count-heuristic
# -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
# -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
# -fsched-stalled-insns-dep -fschedule-fusion -fschedule-insns2
# -fsemantic-interposition -fshow-column -fshrink-wrap -fsigned-zeros
# -fsplit-ivs-in-unroller -fsplit-wide-types -fssa-phiopt -fstack-protector
# -fstdarg-opt -fstrict-volatile-bitfields -fsync-libcalls -fthread-jumps
# -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp -ftree-builtin-call-dce
# -ftree-ccp -ftree-ch -ftree-coalesce-vars -ftree-copy-prop
# -ftree-copyrename -ftree-cselim -ftree-dce -ftree-dominator-opts
# -ftree-dse -ftree-forwprop -ftree-fre -ftree-loop-if-convert
# -ftree-loop-im -ftree-loop-ivcanon -ftree-loop-optimize
# -ftree-parallelize-loops= -ftree-phiprop -ftree-pre -ftree-pta
# -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slsr -ftree-sra
# -ftree-switch-conversion -ftree-tail-merge -ftree-ter -ftree-vrp
# -funit-at-a-time -fvar-tracking -fverbose-asm -fzero-initialized-in-bss
# -m128bit-long-double -m64 -m80387 -maccumulate-outgoing-args
# -malign-stringops -mavx256-split-unaligned-load
# -mavx256-split-unaligned-store -mfancy-math-387 -mfentry -mfp-ret-in-387
# -mfxsr -mglibc -mieee-fp -mlong-double-80 -mno-red-zone -mno-sse4
# -mpush-args -mtls-direct-seg-refs -mvzeroupper

	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.section	.text.unlikely
.Ltext_cold0:
	.text
	.globl	foo
	.type	foo, @function
foo:
.LFB116:
	.file 1 "kernel/bounds.c"
	.loc 1 15 0
	.cfi_startproc
1:	call	__fentry__
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	.loc 1 17 0
#APP
# 17 "kernel/bounds.c" 1
	
->NR_PAGEFLAGS $25 __NR_PAGEFLAGS	#
# 0 "" 2
	.loc 1 18 0
# 18 "kernel/bounds.c" 1
	
->MAX_NR_ZONES $4 __MAX_NR_ZONES	#
# 0 "" 2
	.loc 1 19 0
# 19 "kernel/bounds.c" 1
	
->NR_PCG_FLAGS $3 __NR_PCG_FLAGS	#
# 0 "" 2
	.loc 1 21 0
#NO_APP
	popq	%rbp	#
	.cfi_restore 6
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE116:
	.size	foo, .-foo
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
.Letext0:
	.section	.text.unlikely
.Letext_cold0:
	.file 2 "include/linux/page-flags.h"
	.file 3 "include/linux/mmzone.h"
	.file 4 "include/linux/printk.h"
	.file 5 "include/linux/kernel.h"
	.file 6 "include/linux/page_cgroup.h"
	.section	.debug_info,"",@progbits
.Ldebug_info0:
	.long	0x1f5
	.value	0x4
	.long	.Ldebug_abbrev0
	.byte	0x8
	.uleb128 0x1
	.long	.LASF56
	.byte	0xc
	.long	.LASF57
	.long	.LASF58
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.long	.Ldebug_line0
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF0
	.uleb128 0x2
	.byte	0x1
	.byte	0x8
	.long	.LASF1
	.uleb128 0x2
	.byte	0x2
	.byte	0x5
	.long	.LASF2
	.uleb128 0x2
	.byte	0x2
	.byte	0x7
	.long	.LASF3
	.uleb128 0x3
	.byte	0x4
	.byte	0x5
	.string	"int"
	.uleb128 0x2
	.byte	0x4
	.byte	0x7
	.long	.LASF4
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF5
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF6
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF7
	.uleb128 0x2
	.byte	0x8
	.byte	0x7
	.long	.LASF8
	.uleb128 0x2
	.byte	0x1
	.byte	0x6
	.long	.LASF9
	.uleb128 0x4
	.long	0x73
	.uleb128 0x2
	.byte	0x8
	.byte	0x5
	.long	.LASF10
	.uleb128 0x2
	.byte	0x1
	.byte	0x2
	.long	.LASF11
	.uleb128 0x5
	.long	.LASF43
	.byte	0x4
	.long	0x50
	.byte	0x2
	.byte	0x49
	.long	0x158
	.uleb128 0x6
	.long	.LASF12
	.byte	0
	.uleb128 0x6
	.long	.LASF13
	.byte	0x1
	.uleb128 0x6
	.long	.LASF14
	.byte	0x2
	.uleb128 0x6
	.long	.LASF15
	.byte	0x3
	.uleb128 0x6
	.long	.LASF16
	.byte	0x4
	.uleb128 0x6
	.long	.LASF17
	.byte	0x5
	.uleb128 0x6
	.long	.LASF18
	.byte	0x6
	.uleb128 0x6
	.long	.LASF19
	.byte	0x7
	.uleb128 0x6
	.long	.LASF20
	.byte	0x8
	.uleb128 0x6
	.long	.LASF21
	.byte	0x9
	.uleb128 0x6
	.long	.LASF22
	.byte	0xa
	.uleb128 0x6
	.long	.LASF23
	.byte	0xb
	.uleb128 0x6
	.long	.LASF24
	.byte	0xc
	.uleb128 0x6
	.long	.LASF25
	.byte	0xd
	.uleb128 0x6
	.long	.LASF26
	.byte	0xe
	.uleb128 0x6
	.long	.LASF27
	.byte	0xf
	.uleb128 0x6
	.long	.LASF28
	.byte	0x10
	.uleb128 0x6
	.long	.LASF29
	.byte	0x11
	.uleb128 0x6
	.long	.LASF30
	.byte	0x12
	.uleb128 0x6
	.long	.LASF31
	.byte	0x13
	.uleb128 0x6
	.long	.LASF32
	.byte	0x14
	.uleb128 0x6
	.long	.LASF33
	.byte	0x15
	.uleb128 0x6
	.long	.LASF34
	.byte	0x16
	.uleb128 0x6
	.long	.LASF35
	.byte	0x17
	.uleb128 0x6
	.long	.LASF36
	.byte	0x18
	.uleb128 0x6
	.long	.LASF37
	.byte	0x19
	.uleb128 0x6
	.long	.LASF38
	.byte	0x8
	.uleb128 0x6
	.long	.LASF39
	.byte	0xc
	.uleb128 0x6
	.long	.LASF40
	.byte	0x8
	.uleb128 0x6
	.long	.LASF41
	.byte	0x4
	.uleb128 0x6
	.long	.LASF42
	.byte	0xb
	.byte	0
	.uleb128 0x7
	.long	.LASF44
	.byte	0x4
	.long	0x50
	.byte	0x3
	.value	0x106
	.long	0x188
	.uleb128 0x6
	.long	.LASF45
	.byte	0
	.uleb128 0x6
	.long	.LASF46
	.byte	0x1
	.uleb128 0x6
	.long	.LASF47
	.byte	0x2
	.uleb128 0x6
	.long	.LASF48
	.byte	0x3
	.uleb128 0x6
	.long	.LASF49
	.byte	0x4
	.byte	0
	.uleb128 0x8
	.byte	0x4
	.long	0x50
	.byte	0x6
	.byte	0x4
	.long	0x1ad
	.uleb128 0x6
	.long	.LASF50
	.byte	0
	.uleb128 0x6
	.long	.LASF51
	.byte	0x1
	.uleb128 0x6
	.long	.LASF52
	.byte	0x2
	.uleb128 0x6
	.long	.LASF53
	.byte	0x3
	.byte	0
	.uleb128 0x9
	.string	"foo"
	.byte	0x1
	.byte	0xe
	.quad	.LFB116
	.quad	.LFE116-.LFB116
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0xa
	.long	0x49
	.long	0x1d1
	.uleb128 0xb
	.byte	0
	.uleb128 0xc
	.long	.LASF54
	.byte	0x4
	.byte	0x24
	.long	0x1c6
	.uleb128 0xa
	.long	0x7a
	.long	0x1e7
	.uleb128 0xb
	.byte	0
	.uleb128 0xd
	.long	.LASF55
	.byte	0x5
	.value	0x1bf
	.long	0x1f3
	.uleb128 0x4
	.long	0x1dc
	.byte	0
	.section	.debug_abbrev,"",@progbits
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0xe
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1b
	.uleb128 0xe
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0xe
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x26
	.byte	0
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x28
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x1c
	.uleb128 0xb
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0x4
	.byte	0x1
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x4
	.byte	0x1
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x2e
	.byte	0
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x27
	.uleb128 0x19
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x2117
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xa
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0xb
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0xc
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0xd
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0xe
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0x5
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_aranges,"",@progbits
	.long	0x2c
	.value	0x2
	.long	.Ldebug_info0
	.byte	0x8
	.byte	0
	.value	0
	.value	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"",@progbits
.Ldebug_line0:
	.section	.debug_str,"MS",@progbits,1
.LASF52:
	.string	"PCG_MIGRATION"
.LASF26:
	.string	"PG_head"
.LASF54:
	.string	"console_printk"
.LASF22:
	.string	"PG_reserved"
.LASF47:
	.string	"ZONE_NORMAL"
.LASF29:
	.string	"PG_mappedtodisk"
.LASF36:
	.string	"PG_compound_lock"
.LASF42:
	.string	"PG_slob_free"
.LASF12:
	.string	"PG_locked"
.LASF16:
	.string	"PG_dirty"
.LASF25:
	.string	"PG_writeback"
.LASF23:
	.string	"PG_private"
.LASF37:
	.string	"__NR_PAGEFLAGS"
.LASF34:
	.string	"PG_uncached"
.LASF49:
	.string	"__MAX_NR_ZONES"
.LASF39:
	.string	"PG_fscache"
.LASF56:
	.ascii	"GNU C11 5.4.0 20160609 -m64 -mpreferred-stack-boundary=3 -mt"
	.ascii	"une=generic -mno-red-zone -mcmodel=kernel -maccumulate-outgo"
	.ascii	"ing-args -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -mf"
	.ascii	"entry -march=x86-64 -g -g -O"
	.string	"2 -p -fno-strict-aliasing -fno-common -fno-delete-null-pointer-checks -funit-at-a-time -fstack-protector -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -fno-optimize-sibling-calls -fno-var-tracking-assignments -fno-strict-overflow -fconserve-stack"
.LASF14:
	.string	"PG_referenced"
.LASF28:
	.string	"PG_swapcache"
.LASF44:
	.string	"zone_type"
.LASF7:
	.string	"long unsigned int"
.LASF3:
	.string	"short unsigned int"
.LASF35:
	.string	"PG_hwpoison"
.LASF31:
	.string	"PG_swapbacked"
.LASF38:
	.string	"PG_checked"
.LASF1:
	.string	"unsigned char"
.LASF57:
	.string	"kernel/bounds.c"
.LASF27:
	.string	"PG_tail"
.LASF43:
	.string	"pageflags"
.LASF50:
	.string	"PCG_LOCK"
.LASF4:
	.string	"unsigned int"
.LASF13:
	.string	"PG_error"
.LASF6:
	.string	"long long unsigned int"
.LASF21:
	.string	"PG_arch_1"
.LASF40:
	.string	"PG_pinned"
.LASF19:
	.string	"PG_slab"
.LASF20:
	.string	"PG_owner_priv_1"
.LASF18:
	.string	"PG_active"
.LASF8:
	.string	"sizetype"
.LASF24:
	.string	"PG_private_2"
.LASF5:
	.string	"long long int"
.LASF17:
	.string	"PG_lru"
.LASF9:
	.string	"char"
.LASF32:
	.string	"PG_unevictable"
.LASF41:
	.string	"PG_savepinned"
.LASF46:
	.string	"ZONE_DMA32"
.LASF2:
	.string	"short int"
.LASF55:
	.string	"hex_asc"
.LASF51:
	.string	"PCG_USED"
.LASF58:
	.string	"/home/paul/Desktop/kernel"
.LASF10:
	.string	"long int"
.LASF48:
	.string	"ZONE_MOVABLE"
.LASF15:
	.string	"PG_uptodate"
.LASF53:
	.string	"__NR_PCG_FLAGS"
.LASF0:
	.string	"signed char"
.LASF30:
	.string	"PG_reclaim"
.LASF11:
	.string	"_Bool"
.LASF33:
	.string	"PG_mlocked"
.LASF45:
	.string	"ZONE_DMA"
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits

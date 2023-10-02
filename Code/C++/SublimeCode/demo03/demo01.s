	.file	"demo01.cpp"
 # GNU C++14 (x86_64-win32-seh-rev0, Built by MinGW-W64 project) version 8.1.0 (x86_64-w64-mingw32)
 #	compiled by GNU C version 8.1.0, GMP version 6.1.2, MPFR version 4.0.1, MPC version 1.1.0, isl version isl-0.18-GMP

 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed: 
 # -iprefix D:/mingw64/bin/../lib/gcc/x86_64-w64-mingw32/8.1.0/
 # -U_REENTRANT D:/SublimeCode/demo03/demo01.cpp -mtune=core2 -march=nocona
 # -auxbase-strip D:/SublimeCode/demo03/demo01.s -O2 -fverbose-asm
 # options enabled:  -faggressive-loop-optimizations -falign-labels
 # -fasynchronous-unwind-tables -fauto-inc-dec -fbranch-count-reg
 # -fcaller-saves -fchkp-check-incomplete-type -fchkp-check-read
 # -fchkp-check-write -fchkp-instrument-calls -fchkp-narrow-bounds
 # -fchkp-optimize -fchkp-store-bounds -fchkp-use-static-bounds
 # -fchkp-use-static-const-bounds -fchkp-use-wrappers -fcode-hoisting
 # -fcombine-stack-adjustments -fcommon -fcompare-elim -fcprop-registers
 # -fcrossjumping -fcse-follow-jumps -fdefer-pop
 # -fdelete-null-pointer-checks -fdevirtualize -fdevirtualize-speculatively
 # -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
 # -fexceptions -fexpensive-optimizations -fforward-propagate
 # -ffp-int-builtin-inexact -ffunction-cse -fgcse -fgcse-lm -fgnu-runtime
 # -fgnu-unique -fguess-branch-probability -fhoist-adjacent-loads -fident
 # -fif-conversion -fif-conversion2 -findirect-inlining -finline
 # -finline-atomics -finline-functions-called-once -finline-small-functions
 # -fipa-bit-cp -fipa-cp -fipa-icf -fipa-icf-functions -fipa-icf-variables
 # -fipa-profile -fipa-pure-const -fipa-ra -fipa-reference -fipa-sra
 # -fipa-vrp -fira-hoist-pressure -fira-share-save-slots
 # -fira-share-spill-slots -fisolate-erroneous-paths-dereference -fivopts
 # -fkeep-inline-dllexport -fkeep-static-consts -fleading-underscore
 # -flifetime-dse -flra-remat -flto-odr-type-merging -fmath-errno
 # -fmerge-constants -fmerge-debug-strings -fmove-loop-invariants
 # -fomit-frame-pointer -foptimize-sibling-calls -foptimize-strlen
 # -fpartial-inlining -fpeephole -fpeephole2 -fpic -fplt
 # -fprefetch-loop-arrays -free -freg-struct-return -freorder-blocks
 # -freorder-functions -frerun-cse-after-loop
 # -fsched-critical-path-heuristic -fsched-dep-count-heuristic
 # -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
 # -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
 # -fsched-stalled-insns-dep -fschedule-fusion -fschedule-insns2
 # -fsemantic-interposition -fset-stack-executable -fshow-column
 # -fshrink-wrap -fshrink-wrap-separate -fsigned-zeros
 # -fsplit-ivs-in-unroller -fsplit-wide-types -fssa-backprop -fssa-phiopt
 # -fstdarg-opt -fstore-merging -fstrict-aliasing
 # -fstrict-volatile-bitfields -fsync-libcalls -fthread-jumps
 # -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp
 # -ftree-builtin-call-dce -ftree-ccp -ftree-ch -ftree-coalesce-vars
 # -ftree-copy-prop -ftree-cselim -ftree-dce -ftree-dominator-opts
 # -ftree-dse -ftree-forwprop -ftree-fre -ftree-loop-if-convert
 # -ftree-loop-im -ftree-loop-ivcanon -ftree-loop-optimize
 # -ftree-parallelize-loops= -ftree-phiprop -ftree-pre -ftree-pta
 # -ftree-reassoc -ftree-scev-cprop -ftree-sink -ftree-slsr -ftree-sra
 # -ftree-switch-conversion -ftree-tail-merge -ftree-ter -ftree-vrp
 # -funit-at-a-time -funwind-tables -fverbose-asm -fzero-initialized-in-bss
 # -m128bit-long-double -m64 -m80387 -maccumulate-outgoing-args
 # -malign-double -malign-stringops -mcx16 -mfancy-math-387 -mfentry
 # -mfp-ret-in-387 -mfxsr -mieee-fp -mlong-double-80 -mmmx -mms-bitfields
 # -mno-sse4 -mpush-args -mred-zone -msse -msse2 -msse3 -mstack-arg-probe
 # -mstackrealign -mvzeroupper

	.text
	.p2align 4,,15
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB2060:
	.seh_endprologue
 # D:/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/iostream:74:   static ios_base::Init __ioinit;
	leaq	_ZStL8__ioinit(%rip), %rcx	 #,
	jmp	_ZNSt8ios_base4InitD1Ev	 #
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "hello world!\12\0"
	.text
	.p2align 4,,15
	.def	_ZL6printfPKcz.constprop.0;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZL6printfPKcz.constprop.0
_ZL6printfPKcz.constprop.0:
.LFB2062:
	pushq	%rbx	 #
	.seh_pushreg	%rbx
	subq	$48, %rsp	 #,
	.seh_stackalloc	48
	.seh_endprologue
 # D:/mingw64/x86_64-w64-mingw32/include/stdio.h:349:   __retval = __mingw_vfprintf( stdout, __format, __local_argv );
	movl	$1, %ecx	 #,
 # D:/mingw64/x86_64-w64-mingw32/include/stdio.h:348:   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
	leaq	72(%rsp), %rbx	 #, tmp91
 # D:/mingw64/x86_64-w64-mingw32/include/stdio.h:345: int printf (const char *__format, ...)
	movq	%rdx, 72(%rsp)	 #,
	movq	%r8, 80(%rsp)	 #,
	movq	%r9, 88(%rsp)	 #,
 # D:/mingw64/x86_64-w64-mingw32/include/stdio.h:348:   __builtin_va_list __local_argv; __builtin_va_start( __local_argv, __format );
	movq	%rbx, 40(%rsp)	 # tmp91, MEM[(char * *)&__local_argv]
 # D:/mingw64/x86_64-w64-mingw32/include/stdio.h:349:   __retval = __mingw_vfprintf( stdout, __format, __local_argv );
	call	*__imp___acrt_iob_func(%rip)	 #
	leaq	.LC0(%rip), %rdx	 #,
	movq	%rbx, %r8	 # tmp91,
	movq	%rax, %rcx	 # _2,
	call	__mingw_vfprintf	 #
 # D:/mingw64/x86_64-w64-mingw32/include/stdio.h:352: }
	addq	$48, %rsp	 #,
	popq	%rbx	 #
	ret	
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1579:
	subq	$40, %rsp	 #,
	.seh_stackalloc	40
	.seh_endprologue
 # D:/SublimeCode/demo03/demo01.cpp:4: int main(){
	call	__main	 #
 # D:/SublimeCode/demo03/demo01.cpp:5: 	printf("hello world!\n");
	leaq	.LC0(%rip), %rcx	 #,
	call	_ZL6printfPKcz.constprop.0	 #
 # D:/SublimeCode/demo03/demo01.cpp:7: }
	xorl	%eax, %eax	 #
	addq	$40, %rsp	 #,
	ret	
	.seh_endproc
	.p2align 4,,15
	.def	_GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_main
_GLOBAL__sub_I_main:
.LFB2061:
	subq	$40, %rsp	 #,
	.seh_stackalloc	40
	.seh_endprologue
 # D:/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/iostream:74:   static ios_base::Init __ioinit;
	leaq	_ZStL8__ioinit(%rip), %rcx	 #,
	call	_ZNSt8ios_base4InitC1Ev	 #
	leaq	__tcf_0(%rip), %rcx	 #,
 # D:/SublimeCode/demo03/demo01.cpp:7: }
	addq	$40, %rsp	 #,
 # D:/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/iostream:74:   static ios_base::Init __ioinit;
	jmp	atexit	 #
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_main
.lcomm _ZStL8__ioinit,1,1
	.ident	"GCC: (x86_64-win32-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef

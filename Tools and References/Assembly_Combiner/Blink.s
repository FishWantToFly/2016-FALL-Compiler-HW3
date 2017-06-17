	.file	"Blink.cpp"
	! ABI version
	.abi_2
	! This asm file is generated by compiler
	.flag	verbatim
	! This vector size directive is required for checking inconsistency on interrupt handler
	.vec_size	16
	! ------------------------------------
	! ISA family		: V3M
	! Pipeline model	: N8
	! Code model		: LARGE
	! Endian setting	: little-endian
	! Use SP floating-point instruction	: No
	! Use DP floating-point instruction	: No
	! ABI version		: ABI2
	! ------------------------------------
	! Use conditional move		: Yes
	! Use performance extension	: No
	! Use performance extension 2	: No
	! Use string extension		: No
	! ------------------------------------
	! V3PUSH instructions	: No
	! 16-bit instructions	: No
	! Reduced registers set	: Yes
	! ------------------------------------
	! Optimization level	: -O0
	! ------------------------------------
	! Cache block size	: 16
	! ------------------------------------
	.text
	.align	1
	.global	_Z5setupv
	.type	_Z5setupv, @function
_Z5setupv:
	! BEGIN PROLOGUE
	!     fp needed: 0
	!  pretend_args: 0
	!    local_size: 0
	! out_args_size: 0
	! registers ever_live: $r0, $r1, $ta, $lp, $sp, 
	! function attributes: None
	push.s	{ $lp }
	addi	$sp, $sp, -4
	! END PROLOGUE
	movi	$r0, 13
	movi	$r1, 1
	bal	pinMode
	! BEGIN EPILOGUE
	addi	$sp, $sp, 4
	pop.s	{ $lp }
	ret
	! END EPILOGUE
	.size	_Z5setupv, .-_Z5setupv
	.align	1
	.global	_Z4loopv
	.type	_Z4loopv, @function
_Z4loopv:
	! BEGIN PROLOGUE
	!     fp needed: 0
	!  pretend_args: 0
	!    local_size: 8
	! out_args_size: 0
	! registers ever_live: $r0, $r1, $ta, $lp, $sp, 
	! function attributes: None
	push.s	{ $lp }
	addi	$sp, $sp, -24
	! END PROLOGUE    movi $r0, 3000
    swi $r0, [$sp+40]
    lwi $r0, [$sp+40]
    swi $r0, [$sp+0]
    movi $r0, 3000
    swi $r0, [$sp+40]
    lwi $r0, [$sp+40]
    swi $r0, [$sp+4]
    lwi $r0, [$sp+0]
    swi $r0, [$sp+40]
    movi $r0, 3
    swi $r0, [$sp+44]
    lwi $r2, [$sp+44]
    lwi $r3, [$sp+40]
    divsr $r0, $r1, $r3, $r2
    swi $r0, [$sp+40]
    lwi $r0, [$sp+4]
    swi $r0, [$sp+44]
    movi $r0, 3
    swi $r0, [$sp+48]
    lwi $r0, [$sp+48]
    lwi $r1, [$sp+44]
    mul $r0, $r1, $r0
    swi $r0, [$sp+44]
    lwi $r0, [$sp+44]
    lwi $r1, [$sp+40]
    add $r0, $r1, $r0
    swi $r0, [$sp+40]
    lwi $r0, [$sp+4]
    swi $r0, [$sp+44]
    lwi $r0, [$sp+44]
    lwi $r1, [$sp+40]
    sub $r0, $r1, $r0
    swi $r0, [$sp+40]
    lwi $r0, [$sp+40]
    swi $r0, [$sp+4]
    movi $r0, 13
    movi $r1, 1
    bal digitalWrite
    lwi $r0, [$sp+0]
    bal delay
    movi $r0, 13
    movi $r1, 0
    bal digitalWrite
    lwi $r0, [$sp+4]
    bal delay
	! BEGIN EPILOGUE
	addi	$sp, $sp, 24
	pop.s	{ $lp }
	ret
	! END EPILOGUE
	.size	_Z4loopv, .-_Z4loopv
	.ident	"GCC: (2015-08-24_nds32le-elf-mculib-v3m) 4.9.2"
	! ------------------------------------
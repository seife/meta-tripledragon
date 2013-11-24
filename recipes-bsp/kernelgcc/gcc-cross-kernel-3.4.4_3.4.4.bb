require gcc-cross-initial_${PV}.bb
require gcc-cross-kernel.inc

SRC_URI += " \
	file://gcc-3.4.4-makefile-fix.patch \
	file://gcc-3.4.4-no-gcov-and-gccbug.patch \
"

LIC_FILES_CHKSUM = " \
	file://COPYING;md5=94d55d512a9ba36caa9b7df079bae19f \
	file://COPYING.LIB;md5=7fbc338309ac38fefcd64b04bb903e34 \
"

do_configure_append() {
	### hack so that xgcc can find our binutils' as
	mkdir ${B}/gcc
	mkdir ${B}/gcc/${TARGET_SYS}
	mkdir ${B}/gcc/${TARGET_SYS}/${PV}
	ln -s `which powerpc-poky-linux-as` ${B}/gcc/${TARGET_SYS}/${PV}/as
}

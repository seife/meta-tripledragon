require gcc-cross-initial_${PV}.bb
require gcc-cross-kernel.inc

PR = "${INC_PR}.2"

SRC_URI += " \
	file://gcc-3.4.4-makefile-fix.patch \
	file://gcc-3.4.4-no-gcov-and-gccbug.patch \
"

LIC_FILES_CHKSUM = " \
	file://COPYING;md5=94d55d512a9ba36caa9b7df079bae19f \
	file://COPYING.LIB;md5=7fbc338309ac38fefcd64b04bb903e34 \
"

EXTRA_OECONF_INITIAL = "--with-as=${STAGING_BINDIR_TOOLCHAIN}/${TARGET_SYS}-as"


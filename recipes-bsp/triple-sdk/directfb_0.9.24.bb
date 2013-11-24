require triple-sdk.inc

SUMMARY = "Graphics abstraction library for the Linux Framebuffer Device"
DESCRIPTION = "DirectFB is a thin library that provides developers \
with hardware graphics acceleration, input device handling and \
abstraction, an integrated windowing system with support for \
translucent windows and multiple display layers on top of the \
Linux framebuffer device."
SECTION = "libs"
LICENSE = "LGPLv2.1"

SRC_URI += " \
	file://COPYING.LIB \
"

LIC_FILES_CHKSUM = "file://COPYING.LIB;md5=2d5025d4aa3495befef8f17206a5b0a1"

# inherit autotools pkgconfig
inherit pkgconfig

# hack...
SEPB = "${WORKDIR}/tdsvn/ARMAS"
# directfb overrides this with SEPB
## B = "${WORKDIR}/tdsvn/ARMAS"

INSANE_SKIP_${PN} = "ldflags already-stripped"
INSANE_SKIP_${PN}-dev = "ldflags"

# no idea why the license file is not found without this...
do_configure() {
	cp '${WORKDIR}/COPYING.LIB' '${S}'
}

do_qa_configure() {
	:
}
do_compile() {
	:
}

do_install() {
	# stuff is expected in /stb/lib, so put it there
	install -d ${D}/stb/lib
	install -d ${D}/${libdir}/pkgconfig
	install -d ${D}/${includedir}
	cp -a filesystem-skeleton/stb/lib/directfb-0.9.24 ${D}/stb/lib
	cp -a filesystem-skeleton/stb/lib/*.24 ${D}/${libdir}
	ln -s libdirect-0.9.so.24   ${D}/${libdir}/libdirect.so
	ln -s libfusion-0.9.so.24   ${D}/${libdir}/libfusion.so
	ln -s libdirectfb-0.9.so.24 ${D}/${libdir}/libdirectfb.so
	cp -a cross-enivroment-build/stb/include/directfb ${D}/${includedir}/
	cp -a cross-enivroment-build/stb/lib/pkgconfig/direct.pc   ${D}${libdir}/pkgconfig/
	cp -a cross-enivroment-build/stb/lib/pkgconfig/fusion.pc   ${D}${libdir}/pkgconfig/
	cp -a cross-enivroment-build/stb/lib/pkgconfig/directfb.pc ${D}${libdir}/pkgconfig/
	sed -i -e 's@^prefix=.*@prefix=/usr@' ${D}${libdir}/pkgconfig/*
	# hack: symlink for libjpeg is needed in /stb/lib
	ln -s /usr/lib/libjpeg.so.62 ${D}/stb/lib
}

FILES_${PN} = "\
	/stb \
	${libdir} \
"

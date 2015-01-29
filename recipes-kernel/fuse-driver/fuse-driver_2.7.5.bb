DESCRIPTION = "FUSE Kernel Modulee"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${S}/COPYING;md5=94d55d512a9ba36caa9b7df079bae19f"

PACKAGE_ARCH = "${MACHINE_ARCH}"

inherit module
DEPENDS += "linux-tripledragon gcc3-kernel-cross"

SRC_URI = " \
	http://downloads.sourceforge.net/project/fuse/fuse-2.X/2.7.5/fuse-2.7.5.tar.gz \
	file://fuse-kernel-add-devfs.diff \
"

S = "${WORKDIR}/fuse-${PV}"

SRC_URI[md5sum] = "b428c526d86cf004cca0f8c83270445b"
SRC_URI[sha256sum] = "b688743ad6202fc5b608353ceac6c16f1662154c4b568d3d7f1f4836bcc0eecd"

ARCH = "ppc"
KERNEL_CC = "${CCACHE}${HOST_PREFIX}gcc-3.4.4"

# compile and install is easier than the stuff from module.bbclass
do_configure() {
	cd kernel
	./configure --with-kernel=${STAGING_KERNEL_DIR} --enable-kernel-module
}

do_compile() {
	unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
	cd kernel
	oe_runmake \
		CC="${KERNEL_CC}" \
		CROSS_COMPILE="${HOST_PREFIX}" ARCH=ppc
}

do_install() {
	unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
	cd kernel
	oe_runmake \
		DESTDIR="${D}" \
		CC="${KERNEL_CC}" \
		CROSS_COMPILE="${HOST_PREFIX}" ARCH=ppc \
		install
}

# the original from module.bbclass does clear out MAKEFLAGS...
oe_runmake() {
	bbnote make -e "$@"
	make -e "$@" || die "oe_runmake failed"
}

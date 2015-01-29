SECTION = "kernel"
LICENSE = "GPLv2"

inherit kernel siteinfo

DESCRIPTION = "Linux kernel for the TripleDragon Set Top Box"
COMPATIBLE_MACHINE = "tripledragon"

DEPENDS += "gcc3-kernel-cross"

PR = "r0"

SRC_URI = "https://www.kernel.org/pub/linux/kernel/v2.6/linux-2.6.12.tar.bz2 \
	file://kdiff_00_all.diff \
	file://kernel-fix-td-build.diff \
	file://os/* \
	file://defconfig \
"

SRC_URI[md5sum] = "c5d2a1b62e1dad502c871bba267337d5"
SRC_URI[sha256sum] = "727b55291a2c52f9f6b9f7ef03b2cd9fc54f7d4d1b0b2baed4c3dd6d9a890c71"
LIC_FILES_CHKSUM = "file://COPYING;md5=9579385572eb40eded61dcb07e0038a4"

S = "${WORKDIR}/linux-${PV}"

# let's hope this does not break everything else...
# the old kernel calls it "ppc" instead of "powerpc"
ARCH = "ppc"
# ...and has a different location of the uImage => set it manually
KERNEL_OUTPUT = "arch/${ARCH}/boot/images/${KERNEL_IMAGETYPE}"
# ...and uses an old compiler...
# this is normally defined in meta/classes/kernel-arch.bbclass
KERNEL_CC = "${CCACHE}${HOST_PREFIX}gcc-3.4.4 ${HOST_CC_KERNEL_ARCH}"

KERNEL_DEFCONFIG = "defconfig"

TDKERNEL_CCOPTS = "ARCH=ppc CROSS_COMPILE=${HOST_PREFIX}"

do_patch_append() {
    bb.build.exec_func('add_td_includes', d)
}

add_td_includes() {
	install -d ${S}/include/stb
	cp -a ${WORKDIR}/os/* ${S}/include/stb/
	# hack, newer kernels have tools dir and kernel.bbclass expects it...
	test -d ${S}/tools || mkdir ${S}/tools
}

do_configure_prepend() {
	cp '${WORKDIR}/defconfig' '${S}/.config'
}

oe_runmake() {
	bbnote make ${TDKERNEL_CCOPTS} "$@"
	make ${TDKERNEL_CCOPTS} "$@" || die "oe_runmake failed"
}

do_install_append() {
	# td-drivers contains these modules, too
	rm ${D}/lib/modules/2.6.12/kernel/drivers/usb/host/ohci-hcd.ko
	rm ${D}/lib/modules/2.6.12/kernel/drivers/usb/storage/usb-storage.ko
	rmdir ${D}/lib/modules/2.6.12/kernel/drivers/usb/host
	rmdir ${D}/lib/modules/2.6.12/kernel/drivers/usb/storage
}

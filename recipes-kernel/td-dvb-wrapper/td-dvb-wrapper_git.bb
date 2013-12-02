DESCRIPTION = "Wrapper module which presents the TD frontend as a Linux-DVB compliant device"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${WORKDIR}/COPYING.GPLv2;md5=b234ee4d69f5fce4486a80fdaf4a4263"

inherit module
DEPENDS += "linux-tripledragon gcc-cross-kernel-3.4.4"
# without td-drivers, this does not work.
RDEPENDS_kernel-module-td-dvb-frontend += "td-drivers"

PR = "r1"
SRCREV = "${AUTOREV}"
PV = "0.0+git${SRCPV}"

SRC_URI = " \
	git://gitorious.org/seife/td-dvb-wrapper.git \
	file://COPYING.GPLv2 \
"

S = "${WORKDIR}/git"
ARCH = "ppc"
KERNEL_CC = "${CCACHE}${HOST_PREFIX}gcc-3.4.4 ${HOST_CC_KERNEL_ARCH}"

# compile and install is easier than the stuff from module.bbclass
do_compile() {
	cd ${STAGING_KERNEL_DIR}
	unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
	oe_runmake M=${S} \
		CC="${KERNEL_CC}" LD="${KERNEL_LD}"
}

do_install() {
	cd ${STAGING_KERNEL_DIR}
	unset CFLAGS CPPFLAGS CXXFLAGS LDFLAGS
	oe_runmake DEPMOD=echo INSTALL_MOD_PATH="${D}" M=${S} \
		CC="${KERNEL_CC}" LD="${KERNEL_LD}" \
		modules_install
}

# the original from module.bbclass does clear out MAKEFLAGS...
oe_runmake() {
	bbnote make -e "$@"
	make -e "$@" || die "oe_runmake failed"
}

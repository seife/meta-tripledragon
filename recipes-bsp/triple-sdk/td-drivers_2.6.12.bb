require triple-sdk.inc

SUMMARY = "Kernel drivers for the Tripledragon STB"
SECTION = "kernel"
# the license is GPL but the source is not available, and no
# company exists anymore to blame for this :-(
LICENSE = "GPLv2"

LIC_FILES_CHKSUM = "file://${WORKDIR}/COPYING.GPLv2;md5=d9f7497c382d9ee2709f9d1b560aecaf"

SRC_URI += " \
	file://COPYING.GPLv2 \
	file://td-drivers.init \
"

# hack...
B = "${WORKDIR}/tdsvn/ARMAS"

do_qa_configure() {
	:
}
do_compile() {
	:
}

do_install() {
	install -d ${D}/lib
	cp -a filesystem-skeleton/lib/modules ${D}/lib/
	install -d ${D}${sysconfdir}/init.d
	install -m 0755 ${WORKDIR}/td-drivers.init ${D}${sysconfdir}/init.d/td-drivers
}

# initscript
inherit update-rc.d

INITSCRIPT_NAME = "td-drivers"
INITSCRIPT_PARAMS = "start 50 S ."

FILES_${PN} = "\
	/lib/modules \
	${sysconfdir} \
"

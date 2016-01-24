require triple-sdk.inc

SUMMARY = "Development headers for the Tripledragon STB"
SECTION = "libs"
LICENSE = "unknown"

SRC_URI += " \
	file://unknown \
	file://triple-sdk.sh \
	file://xp_osd_user.h \
"

LIC_FILES_CHKSUM = "file://unknown;md5=d9f7497c382d9ee2709f9d1b560aecaf"

# hack...
B = "${WORKDIR}/tdsvn/ARMAS"

# no idea why the license file is not found without this...
do_configure() {
	cp '${WORKDIR}/unknown' '${S}'
}

do_qa_configure() {
	:
}
do_compile() {
	:
}

do_install() {
	install -d ${D}/${includedir}
	install -d ${D}/${bindir}
	install -m0755 ${WORKDIR}/triple-sdk.sh ${D}/${bindir}/
	cp -a cross-enivroment-build/stb/include/hardware ${D}/${includedir}/
	cp -a ${WORKDIR}/xp_osd_user.h ${D}/${includedir}/hardware/xp
}

# silence license warning...
do_populate_lic() {
	:
}

FILES_${PN}-dev = "\
	${includedir} \
"

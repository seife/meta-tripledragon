FILESEXTRAPATHS_prepend := "${THISDIR}/triple-sdk-1.0:"

DEPENDS += "xz-native"

# these packages are only useful for this machine...
COMPATIBLE_MACHINE = "tripledragon"
PACKAGE_ARCH = "${MACHINE_ARCH}"

SRC_URI = " \
	file://tdsvn-essential.tar.lzma \
"

SRC_URI[md5sum] = "fb369a5801f7df5c850d2d6a21abefe0"
SRC_URI[sha256sum] = "257d5c01559672309923b68283f611cc2a18f83ea85f8b59e90e879043ec05f2"

CLEANFUNCS += "clean_tdsvn"

do_unpack_append () {
    bb.build.exec_func('unpack_tdsvn', d)
}

unpack_tdsvn() {
	cd ${WORKDIR}
	xz -dc tdsvn-essential.tar.lzma | tar x --no-same-owner -f -
}

python clean_tdsvn() {
	dir = d.expand("${WORKDIR}/tdsvn")
	bb.note("Removing " + dir)
	oe.path.remove(dir)
}

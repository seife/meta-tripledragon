FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
PRINC := "${@int(PRINC) + 1}"

# this is TD specific
PACKAGE_ARCH = "${MACHINE_ARCH}"

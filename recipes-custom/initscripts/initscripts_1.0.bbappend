FILESEXTRAPATHS_prepend := "${THISDIR}/files:"
# PRINC is deprecated in daisy
#PRINC := "${@int(PRINC) + 2}"

# this is TD specific
PACKAGE_ARCH = "${MACHINE_ARCH}"

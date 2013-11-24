//--------------------------------------------------------------------------
// Authors:	(C)2003 André D. / Uli H.
//--------------------------------------------------------------------------
#ifndef __PVERSION_H_INC__
#define __PVERSION_H_INC__

#include <linux/kernel.h>
#include <linux/version.h>

	#ifndef _DRV_VERSION_
		#ifndef  __DRV_VERSION__  // current version
			#error "No __DRV_VERSION__ is defined before including pversion.h"
		#endif
	#endif

	#ifdef _CDEBUG_
		#define PVERSION(module_name)	printk(KERN_NOTICE "%s " __DRV_VERSION__ " - Built " __DATE__ "/" __TIME__ " for " UTS_RELEASE " (debug)\n", module_name )
	#else
		#define PVERSION(module_name)	printk(KERN_NOTICE "%s " __DRV_VERSION__ " - Built " __DATE__ "/" __TIME__ " for " UTS_RELEASE " (none debug)\n", module_name )
	#endif

	#ifdef _CDEBUG_
		#define PMVERSION()	printk(KERN_NOTICE "%s " _DRV_VERSION_ " - Built " __DATE__ "/" __TIME__ " for " UTS_RELEASE " (debug)\n", _DRV_NAME_ )
	#else
		#define PMVERSION()	printk(KERN_NOTICE "%s " _DRV_VERSION_ " - Built " __DATE__ "/" __TIME__ " for " UTS_RELEASE " (none debug)\n", _DRV_NAME_ )
	#endif

#endif


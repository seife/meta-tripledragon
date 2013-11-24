//---------------------------------------------------------------------------
// (C)2003 André D. / Uli H.
//---------------------------------------------------------------------------
#ifndef  _DRV_INCLUDE_OS_OS_GENERIC_H_INC_
#define  _DRV_INCLUDE_OS_OS_GENERIC_H_INC_

#include <linux/mm.h>
#include <linux/slab.h>														// where kmalloc/kfree is defined
#include <linux/interrupt.h>												// where in_interrupt defined
#include <linux/kernel.h>

#include "os-types.h"


//--------------------------------------------------------------------------
#undef SLEEP
#define SLEEP(ms)	set_current_state(TASK_INTERRUPTIBLE); \
                    schedule_timeout( (HZ * ms) / 1000 );



//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
#if defined _LDEBUG_ && !defined _GDEBUGDISABLE_
	#define GDEB_IF(flags, mask) if( !(~flags & mask) )
	#define GDEB_EPRINTK(flags, mask, format, args...) if( !(~flags & mask) ) printk( "\r\x1b[1;31m[%s] \x1b[0mError: " format, __FUNCTION__, ##args)
	#define GDEB_DPRINTK(flags, mask, format, args...) if( !(~flags & mask) ) printk( "\r\x1b[34m[%s] \x1b[0m" format, __FUNCTION__, ##args)
	#define GDEB_FPRINTK(flags, mask, format, args...) if( !(~flags & mask) ) printk( format, ##args)
	#define _CDEBUG_
#else
	#define GDEB_IF(flags, mask) if(0)
	#define GDEB_EPRINTK(flags, mask, format, args...) ( { } )
	#define GDEB_DPRINTK(flags, mask, format, args...) ( { } )
	#define GDEB_FPRINTK(flags, mask, format, args...) ( { } )
	#undef _CDEBUG_
#endif


#ifndef _GDEBUGDISABLE_
	#define EPRINTK( format, args... ) printk( "\r\x1b[1;31m[%s] \x1b[0mError: " format, __FUNCTION__, ##args )
	#define DPRINTK( format, args... ) printk( "\r\x1b[34m[%s] \x1b[0m" format, __FUNCTION__, ##args )
	#define WPRINTK( format, args... ) printk( "\x1b[1;35m[%s] \x1b[0m" format, __FUNCTION__, ##args )
	#define FPRINTK( format, args... ) printk( format, ##args )

#define xdump(adr, cnt) { \
		u8 *xtmpadr = adr; \
		u16 zcnt; \
		for( zcnt=0; zcnt<cnt; zcnt++ ) printk( " %.2X", xtmpadr[zcnt] ); \
		printk( "\n" ); \
	}

#else /* NDEBUG */
	#define EPRINTK(format, args...) ( { } )
	#define DPRINTK( format, args... ) ( { } )
	#define FPRINTK( format, args... ) ( { } )
	#define WDEBUG( format, args... )  ( { } )

#define xdump(adr, cnt) ( { } )

#endif


#define xdump(adr, cnt) { \
		u8 *xtmpadr = adr; \
		u16 zcnt; \
		for( zcnt=0; zcnt<cnt; zcnt++ ) printk( " %.2X", xtmpadr[zcnt] ); \
		printk( "\n" ); \
	}


#endif  //  _DRV_INCLUDE_OS_OS_GENERIC_H_INC_




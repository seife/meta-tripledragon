//--------------------------------------------------------------------------
//	(C)2003 André D. / Uli H.
//--------------------------------------------------------------------------
//	File:	include/os/os-types.h
//--------------------------------------------------------------------------

#ifndef  _DRV_INCLUDE_OS_OS_TYPES_H_INC_
#define  _DRV_INCLUDE_OS_OS_TYPES_H_INC_

#include <linux/version.h>
#include <asm/io.h>     // for OS defined io routines


// Architecture specific
typedef signed int INT;
typedef unsigned int UINT;

typedef signed short int SHORT;
typedef unsigned short int USHORT;

typedef unsigned char BYTE;
typedef unsigned char UCHAR;

typedef signed char SBYTE;

typedef signed long LONG;
typedef unsigned long ULONG;


//try to be architecture independent
// for PPC 4xx, the following is true
typedef signed char INT8;
typedef unsigned char UINT8;

typedef short signed int INT16;
typedef unsigned short int UINT16;

typedef signed int INT32;
typedef unsigned int UINT32;

// only gcc support these
typedef signed long long int INT64;
typedef unsigned long long int UINT64;


typedef struct tagTaskMsg {
  unsigned int	uMsgType;
  unsigned long	ulPara1;
  unsigned long	ulPara2;
}TASK_MSG;






#define uchar unsigned char
#define sint signed int
#define schar signed char

#ifndef sshort
	#define sshort signed short
#endif

#ifndef ushort
	#define ushort unsigned short
#endif


#ifndef u8
	typedef unsigned char u08;
#endif

#ifndef s8
	typedef signed char s08;
#endif

#ifndef U8
	typedef unsigned char U8;
	typedef unsigned char U08;
#endif

#ifndef S8
	typedef signed char S8;
	typedef signed char S08;
#endif

#ifndef U16
	typedef unsigned short U16;
#endif



#ifndef __KERNEL__
	typedef signed char s8;
	typedef unsigned char u8;

	typedef signed short s16;
	typedef unsigned short u16;

	typedef signed int s32;
	typedef unsigned int u32;

	typedef signed long long s64;
	typedef unsigned long long u64;
#endif










#define __to_asm_token(s)   #s
#define MF_DCR(rn) __mfdcr_or_dflt(rn, 0)

#define __mfdcr_or_dflt(rn,default_rval) \
		({unsigned int rval;                                            \
		if (rn == 0)                                                    \
				rval = default_rval;                                    \
		else                                                            \
				asm volatile("mfdcr %0," __to_asm_token(rn) : "=r" (rval));  \
		rval;})

#define MT_DCR(rn, v)  \
		{if (rn != 0) \
				asm volatile("mtdcr " __to_asm_token(rn) ",%0" : : "r" (v));}


#define MF_SPR(rn) __mfspr_or_dflt(rn, 0)

#define __mfspr_or_dflt(rn,default_rval) \
		({unsigned int rval;                                            \
		if (rn == 0)                                                    \
				rval = default_rval;                                    \
		else                                                            \
				asm volatile("mfspr %0," __to_asm_token(rn) : "=r" (rval));  \
		rval;})

#define MT_SPR(rn, v)  \
		{if (rn != 0) asm volatile("mtspr " __to_asm_token(rn) ",%0" : : "r" (v));}


// BYTE
#define _OS_INB(uPort)           in_8((volatile BYTE *)(uPort))
#define _OS_OUTB(uPort, data)    out_8((volatile BYTE *)(uPort), (int)(data))

// big endian I/O routines
// USHORT (16)
#define _OS_INW(uPort)           in_be16((volatile USHORT *)(uPort))
#define _OS_OUTW(uPort, data)    out_be16((volatile USHORT *)(uPort), (int)(data))

// UINT (32)
#define _OS_INL(uPort)           in_be32((volatile UINT32 *)(uPort))
#define _OS_OUTL(uPort, data)    out_be32((volatile UINT32 *)(uPort), (int)(data))

// little endian I/O routines
// USHORT (16)
#define _OS_INWX(uPort)          in_le16((volatile USHORT *)(uPort))
#define _OS_OUTWX(uPort, data)   out_le16((volatile USHORT *)(uPort), (int)(data))

// UINT (32)
#define _OS_INLX(uPort)          in_le32((volatile UINT32 *)(uPort))
#define _OS_OUTLX(uPort, data)   out_1e32((volatile UINT32 *)(uPort), (int)(data))


#ifndef ansi_n

	#define ansi_clr_tabs	"\x1b[3g"
	#define ansi_set_tab	"\x1bH"

	#define ansi_cls0 "\x1b[0J"
	#define ansi_cls2 "\x1b[2J"

	#define ansi_sav_cursor			"\x1b" "7"
	#define ansi_rst_cursor			"\x1b" "8"
	#define ansi_mode_origin_abs	"\x1b[?6l"


	#define ansi_n "\x1b[0m"

	#define ansi_light "\x1b[1m"
	#define ansi_blink "\x1b[5m"
	#define ansi_revrs "\x1b[7m"

	#define ansi_red "\x1b[31m"
	#define ansi_grn "\x1b[32m"
	#define ansi_yel "\x1b[33m"
	#define ansi_blu "\x1b[34m"
	#define ansi_mgn "\x1b[35m"
	#define ansi_cya "\x1b[36m"
	#define ansi_wht "\x1b[37m"

	#define ansi_redlight "\x1b[1;31m"
	#define ansi_grnlight "\x1b[1;32m"
	#define ansi_yellight "\x1b[1;33m"
	#define ansi_blulight "\x1b[1;34m"
	#define ansi_mgnlight "\x1b[1;35m"
	#define ansi_cyalight "\x1b[1;36m"
	#define ansi_whtlight "\x1b[1;37m"

	#define ansi_redblink "\x1b[5;31m"
	#define ansi_grnblink "\x1b[5;32m"
	#define ansi_yelblink "\x1b[5;33m"
	#define ansi_blublink "\x1b[5;34m"
	#define ansi_mgnblink "\x1b[5;35m"
	#define ansi_cyablink "\x1b[5;36m"
	#define ansi_whtblink "\x1b[5;37m"

	#define ansi_redrevrs "\x1b[7;31m"
	#define ansi_grnrevrs "\x1b[7;32m"
	#define ansi_yelrevrs "\x1b[7;33m"
	#define ansi_blurevrs "\x1b[7;34m"
	#define ansi_mgnrevrs "\x1b[7;35m"
	#define ansi_cyarevrs "\x1b[7;36m"
	#define ansi_whtrevrs "\x1b[7;37m"

	#define ansi_redlightrevrs "\x1b[1;7;31m"
	#define ansi_grnlightrevrs "\x1b[1;7;32m"
	#define ansi_yellightrevrs "\x1b[1;7;33m"
	#define ansi_blulightrevrs "\x1b[1;7;34m"
	#define ansi_mgnlightrevrs "\x1b[1;7;35m"
	#define ansi_cyalightrevrs "\x1b[1;7;36m"

	#define ansi_redflash "\x1b[1;5;7;31m"

	#define ansi_error ansi_mgnblink
	#define ansi_disable ansi_light
#endif		// ansi_n, ansi stuff

#ifdef __KERNEL__
typedef enum {
	false = 0,
	true = 1
} bool;
#endif

#endif /*  _DRV_INCLUDE_OS_OS_TYPES_H_INC_ */

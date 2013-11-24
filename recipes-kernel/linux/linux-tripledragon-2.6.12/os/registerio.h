//--------------------------------------------------------------------------
//	(C)2003 Andr‚ D. / Uli H.
//--------------------------------------------------------------------------
//	File Name:	include/os/registerio.h
//	Function:	extended register definitions
//--------------------------------------------------------------------------
#ifndef __REGISTERIO_H__
#define __REGISTERIO_H__


#define R1_TU0_LNB_OFF			0x01										// H=OFF, L=ON
#define R1_TU0_22KHZ_ON			0x02										// H=22KHz ON, L=OFF
#define R1_TU0_VERTICAL			0x04										// H=vertical=14V, L=horizontal=18V
#define R1_TU0_EXT_LNB			0x08										// H=ext. LNB loop, l=internal LNB power
#define R1_TU0_DVBT_ANTPWR		0x10										// H=OFF, L=ON
#define R1_TU0_LNB_BOOST		0x20										// H=OFF, L=ON
#define R1_TU0_DVBT_PWRSEL		0x40
#define R1_TU0_RES_80			0x80

#define R2_CH0_FTA_SEL			0x01										// H=FTA, L=CI
#define R2_T63					0x02										//
#define R2_T64					0x04										//
#define R2_T65					0x08										//
#define R2_T66					0x10										//
#define R2_3V3_2V5_ENA			0x20										// CPU H=3V3, 2V5 output
#define R2_5V_12V_ENA			0x40										// LCD H=5V, 12V output
#define R2_HDD_5V_12V_ENA		0x80										// HDD Power output

#define R3_12V_ON				0x01										// H=12V, L=0V
#define R3_HDD_RESET_OFF		0x02										// H=normal, L=Reset
#define R3_SLA_USB_RESET_OFF	0x04										// h=normal, L=Reset
#define R3_MODEM_RESET_OFF 		0x08										// H=normal, L=Reset
#define R3_ETHERNET_RESET_OFF	0x10										// H=normal, L=Reset
#define R3_TU0_RESET_OFF		0x20										// H=normal, L=Reset
#define R3_TU1_RESET_OFF		0x40										// H=normal, L=Reset
#define R3_MODULATOR_ON			0x80										// H=ON, L=OFF

//--------------------------------------------------------------------------
extern u8 *hwa_scratchr0;													// scratch-register 0 remapped address

extern u16 *hwa_register1;													// register_1 remapped logical address (access this to write)
extern u16 *hwa_register2;													// register_2 remapped logical address (access this to write)
extern u16 *hwa_register3;													// register_3 remapped logical address (access this to write)

extern u16 hwv_register1;													// register_1 working data (hardware is read-only)
extern u16 hwv_register2;													// register_2 working data (hardware is read-only)
extern u16 hwv_register3;													// register_3 working data (hardware is read-only)

#define I2C_DRIVERID_IBMOCP   0xf453
extern struct i2c_driver dbs3000driver;
extern struct i2c_client i2c_client_scart;									// I2C-client A/V-Switch
extern struct i2c_client i2c_client_modulator;								// I2C-client RF-Modulator
extern struct i2c_client i2c_client_stuner;									// I2C-client DVB-S Tuner
//extern struct i2c_client i2c_client_ctuner;								// I2C-client DVB-C Tuner
extern struct i2c_client i2c_client_ttuner;									// I2C-client DVB-T Tuner
extern struct i2c_client i2c_client_pll_cx;									// I2C-client PLL

s16 __hwa_get_register_1(void);
s16 __hwa_set_register_1(u16 newvalue);

s16 __hwa_get_register_2(void);
s16 __hwa_set_register_2(u16 newvalue);

s16 __hwa_get_register_3(void );
s16 __hwa_set_register_3(u16 newvalue);

void fp_backlight_off(void);
void fp_backlight_on(void);

u16 pw_cdhd_off(void);
u16 pw_cdhd_on(void);

#endif	// __REGISTERIO_H__


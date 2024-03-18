#ifndef __LOVYANGFX_PINS_ILI9488_H__
#define __LOVYANGFX_PINS_ILI9488_H__

//////////////////////////////////////////////////////////////////////////
/*
	ESP32 | LVGL8 | Ep 0. GFX Setup (ft. LovyanGFX)
	Developing Embedded GUI with SquareLine Studio [2/2]
	Configuración de lv_conf.h
	Video Tutorial: https://youtu.be/b_4m1A3A2yw
	Created by That Project
*/
//////////////////////////////////////////////////////////////////////////
/*
	Modificado: Ernesto José Guerrero González, Civil Engineering ud FJdC.
*/
//////////////////////////////////////////////////////////////////////////
#define HMI_TFT_ILI9488_480x320

#if defined(HMI_TFT_ILI9488_480x320)
// Pines TFT ILI9488 480x320.
#define LCD_SCK 	18	//	cfg.pin_sclk = 	18;
#define LCD_MOSI 	23	//	cfg.pin_mosi = 	23;
#define LCD_MISO 	19	//	cfg.pin_miso = 	19;
#define LCD_SS0 	15	//	cfg.pin_cs =	15;
#define LCD_SS1 	21	//	cfg.pin_cs =	21;
#define LCD_SS2 	-1	//	cfg.pin_cs =	5;

#define SPI_DC		2	//	cfg.pin_dc   = 	2;
#define PIN_RST		4	//	cfg.pin_rst = 	4;
#define PIN_BL		32	//	cfg.pin_bl =	32;

#define PIN_BUSY	-1	//	cfg.pin_busy = 	-1;
#define PIN_INT		-1	//	cfg.pin_int =	-1;

#elif defined(HMI_ESP32_4827S043)
// Pines TFT HMI ESP32 4827S043 - ESP32-S3 480x320
#define LCD_SCK     12  //  cfg.pin_sclk =  12;
#define LCD_MOSI    13  //  cfg.pin_mosi =  13;
#define LCD_MISO    14  //  cfg.pin_miso =  14;
#define LCD_SS0     3   //  cfg.pin_cs =    3;
#define LCD_SS1 	-1	//	cfg.pin_cs =	-1;
#define LCD_SS2 	-1	//	cfg.pin_cs =	-1;

#define SPI_DC		42	//	cfg.pin_dc   = 	42;
#define PIN_RST		-1	//	cfg.pin_rst = 	-1;
#define PIN_BL		46	//	cfg.pin_bl =	46;

#define PIN_BUSY	-1	//	cfg.pin_busy = 	-1;
#define PIN_INT		-1	//	cfg.pin_int =	-1;

#endif

#endif // __LOVYANGFX_PINS_ILI9488_H__
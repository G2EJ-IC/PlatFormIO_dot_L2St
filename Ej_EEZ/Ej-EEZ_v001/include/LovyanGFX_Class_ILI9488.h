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

#ifndef __CLASSILI9488_H__
#define __CLASSILI9488_H__

//#include <Arduino.h>

// LovyanGFX
// https://github.com/lovyan03/LovyanGFX
#define LGFX_USE_V1
#include <LovyanGFX.hpp>
#include "config.h"

static const uint32_t TFT_WIDTH = 320;
static const uint32_t TFT_HEIGHT = 480;

class LGFX : public lgfx::LGFX_Device
{
	lgfx::Panel_ILI9488     _panel_instance;
	lgfx::Bus_SPI        _bus_instance; // instancia de bus SPI
	lgfx::Light_PWM     _light_instance;
	
	// Prepara una instancia que coincida con el tipo de pantalla táctil. (Eliminar si no es necesario)
	lgfx::Touch_XPT2046          _touch_instance;

	public:
	LGFX(void)
	{
		{ // Configurar los ajustes de control del bus.
			auto cfg = _bus_instance.config(); // Obtener la estructura de configuración del bus.
			
			cfg.spi_host = VSPI_HOST;  // Selecciona el SPI a usar (VSPI_HOST o HSPI_HOST)
			cfg.spi_mode = 0;          // Establecer el modo de comunicación SPI (0 ~ 3)
			cfg.freq_write = 60000000; // Reloj SPI al transmitir (máximo 80MHz, redondeado a 80MHz dividido por un número entero) // cfg.freq_write = 60000000;
			cfg.freq_read  = 16000000; // reloj SPI al recibir
			cfg.spi_3wire  = false;    // Se establece en verdadero si la recepción se realiza mediante el pin MOSI
			cfg.use_lock   = true;     // Establecer verdadero para usar el bloqueo de transacciones
			cfg.dma_channel = 1;       // Configura el canal DMA (1 o 2. 0=deshabilitar) Configura el canal DMA a usar (0=DMA no usado)
			
			//Pines GPIO
			cfg.pin_sclk = LCD_SCK;    // Establece el número de pin SPI SCLK									//	VSPI_SCK	//	GPIO18
			cfg.pin_mosi = LCD_MOSI;   // Establece el número de pin SPI MOSI									//	VSPI_MOSI	//	GPIO23
			cfg.pin_miso = LCD_MISO;   // Establece el número de pin SPI MISO (-1 = desactivar)					//	VSPI_MISO	//	GPIO19
			cfg.pin_dc   = SPI_DC;     // Establece el número de pin SPI D/C (-1 = desactivar)					//	ADC12		//	GPIO2
			
			_bus_instance.config(cfg); // Refleja la configuración en el bus.
			_panel_instance.setBus(&_bus_instance);     // Configura el bus en el panel.
		}

		{ // Establecer el control del panel de visualización.
			auto cfg = _panel_instance.config(); // Obtiene la estructura para la configuración del panel de visualización.
			
			//Pines GPIO.
			cfg.pin_cs = 		LCD_SS0;	// Número de pin al que está conectado el CS (-1 = deshabilitar)	//	GPIO15
			cfg.pin_rst = 		PIN_RST;	// Número de pin al que está conectado RST (-1 = deshabilitar)		//	GPIO4
			cfg.pin_busy =		PIN_BUSY;	// Número de pin al que está conectado BUSY (-1 = deshabilitar)		// -1
			
			cfg.memory_width = TFT_WIDTH;	// Ancho máximo admitido por el controlador IC
			cfg.memory_height = TFT_HEIGHT;	// Altura máxima admitida por el controlador IC
			cfg.panel_width = TFT_WIDTH;		// Ancho visualizable real
			cfg.panel_height = TFT_HEIGHT;	// Altura de visualización real
			cfg.offset_x = 0;				// Cantidad de desplazamiento de dirección del panel X
			cfg.offset_y = 0;				// Cantidad de compensación de dirección del panel Y
			cfg.offset_rotation = 0;		// Desplazamiento del valor de dirección de rotación 0~7 (4~7 están al revés)
			cfg.dummy_read_pixel = 8;		// Número de bits para lectura ficticia antes de la lectura de píxeles
			cfg.dummy_read_bits = 1;		// Número de bits para lectura ficticia antes de leer datos distintos de píxeles
			cfg.readable = true;			// Establecer en verdadero si los datos se pueden leer
			cfg.invert = false;				// Se establece en verdadero si el brillo del panel se invierte
			cfg.rgb_order = false;			// Se establece en verdadero si se intercambian los colores rojo y azul del panel
			cfg.dlen_16bit = false;			// Establecido en verdadero para paneles que envían longitud de datos en unidades de 16 bits
			cfg.bus_shared = true;			// Se establece en verdadero si el bus se comparte con la tarjeta SD (controla el bus con drawJpgFile, etc.)
			
			_panel_instance.config(cfg);
		}

		{ // Establecer el control de retroiluminación. (Eliminar si no es necesario)
			auto cfg = _light_instance.config(); // Obtiene la estructura para la configuración de la retroiluminación.
			
			cfg.pin_bl = PIN_BL;			// Número de pin al que está conectada la retroiluminación	//	GPIO32
			
			cfg.invert = false; 			// true para invertir el brillo de la retroiluminación					
			cfg.freq = 44100; 				// Frecuencia de retroiluminación PWM
			cfg.pwm_channel = 7; 			// número de canal PWM a utilizar
			
			_light_instance.config(cfg);
			_panel_instance.setLight(&_light_instance); // Establece la luz de fondo en el panel.
		}

		{ // Configurar los ajustes de control de la pantalla táctil. (Eliminar si no es necesario)
			auto cfg = _touch_instance.config();
			
			cfg.x_min = 			0; 				// Valor mínimo X obtenido de la pantalla táctil (valor bruto)
			cfg.x_max = 			TFT_WIDTH - 1; 	// Valor máximo de X obtenido de la pantalla táctil (valor bruto)
			cfg.y_min = 			0; 				// Valor mínimo Y obtenido de la pantalla táctil (valor bruto)
			cfg.y_max = 			TFT_HEIGHT - 1; // Valor máximo Y obtenido de la pantalla táctil (valor bruto)
			cfg.pin_int = 			PIN_INT; 		// Número de pin al que está conectado INT	//	-1
			cfg.bus_shared = 		true; 			// Establece como verdadero si usa el mismo bus que la pantalla
			cfg.offset_rotation = 	0;				// Ajuste cuando la dirección de visualización y tacto no coinciden Establecer con un valor de 0 a 7
			cfg.spi_host = 			VSPI_HOST;		// Seleccione el SPI a usar (HSPI_HOST o VSPI_HOST)
			cfg.freq = 				1000000; 		// Configurar el reloj SPI
			
			//Pines GPIO _touch_instance.
			cfg.pin_sclk = 	LCD_SCK;	// Número de pin al que está conectado SCLK		//	GPIO18
			cfg.pin_mosi = 	LCD_MOSI;	// Número de pin al que está conectado MOSI		//	GPIO23
			cfg.pin_miso = 	LCD_MISO; 	// Número de pin al que está conectado MISO		//	GPIO19
			cfg.pin_cs = 	LCD_SS1;	// Número de pin al que está conectado CS		//	GPIO21
			
			_touch_instance.config(cfg);
			_panel_instance.setTouch(&_touch_instance); // Configura la pantalla táctil en el panel.
		}
		setPanel(&_panel_instance); //Configura el panel a utilizar.
	}
};

#endif // __CLASSILI9488_H__
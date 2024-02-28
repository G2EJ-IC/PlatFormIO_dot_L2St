#ifndef __CONECTARWIFI_IOT_H__
#define __CONECTARWIFI_IOT_H__

#include <Arduino.h>

// #if defined(ESP8266)
//     //Librerias WiFiManager
//     #include <ESP8266WiFi.h>
//     //#include <wm_strings_en.h>
//     #include <ESP8266WebServer.h>
// #elif defined(ESP32)
//     //Librerias WiFiManager
//     #include <WiFi.h>
//     //#include <wm_strings_en.h>
//     #include <WebServer.h>
// #endif

// #include <DNSServer.h>
// #include <WiFiManager.h>

/**
 * @brief Breve descripción.
 * @param Parámetros.
 * @return Salida. 
 */
void ResetWiFi_IoT();

/**
 * @brief Breve descripción.
 * @param Parámetros.
 * @return Salida. 
 */
void ConectarWiFi_IoT();

#endif // __CONECTARWIFI_IOT_H__
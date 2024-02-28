#include <Arduino.h>
/** 
* @brief : Función Similar a cout << de C++, Debe estar despues de #include <Arduino.h> para que funcione.
* @param : T.
* @return : obj.
*/
template<class T>
inline Print &operator <<(Print &obj, T arg) { 
    obj.print(arg); 
    return obj; 
}

#include <ConectarWiFi_IoT.h>
//Librerias WiFiManager
#include <WiFi.h>
//#include <wm_strings_en.h>
#include <WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>


//Instancia de la Clase WiFiManager.
WiFiManager wifiManager;

bool Conecto;

void ResetWiFi_IoT() {
    Serial << "\r\n";
    //Resetear Configuración.
    wifiManager.resetSettings();
    Serial << "\r\n\n\n\nReseteo de Redes WiFi Guardadas.... "; 
}

void ConectarWiFi_IoT() {
    if (WiFi.status() != WL_CONNECTED) {
        //---------------------------Monitor serial-----------------------------//
        Serial << "\r\n";
        Serial << "\r\n=========================================================";
        Serial << "\r\nUniversidad Distrital Francisco José de Caldas";
        Serial << "\r\nFacultad Tecnológica | Maestría en Ingeniería Civil";
        Serial << "\r\nMonitoreo AIoT | @2024";
        Serial << "\r\nErnesto Jose Guerrero Gonzalez, IC, MSc(C), Esp.";
        Serial << "\r\n=========================================================";
        Serial << "\r\n\n";
        Serial << "\r\nPor favor, conecte el celular a la red (.:: AIoT_NodeESP32 ::.) y configure WiFi.... ";
        Serial << "\r\n\n\n";

        //Crear AP y Portal Cautivo.
        Conecto = wifiManager.autoConnect(".:: AIoT_NodeESP32 ::.");
        
        if (!Conecto) {
            Serial << "\r\nFallo la Conección (timeout - NOK)";
            ESP.restart();
            delay(1000);
        }

        Serial << "\r\n\n\n\nYa esta conectado.... ";

        if (WiFi.status() == WL_CONNECTED) {
            Serial << "\r\n\n";
            Serial << "\r\nConectado a WiFi (OK).: ";
            Serial << "\r\nConectado a la Red WiFi (SSID).: " << String(WiFi.SSID());
            Serial << "\r\nDirección IP .: " << WiFi.localIP().toString();
            Serial << "\r\nDirección DNS.: " << WiFi.dnsIP().toString();
            Serial << "\r\nDirección MAC.: " << WiFi.macAddress();
            Serial << "\r\n";
        }
    }
}
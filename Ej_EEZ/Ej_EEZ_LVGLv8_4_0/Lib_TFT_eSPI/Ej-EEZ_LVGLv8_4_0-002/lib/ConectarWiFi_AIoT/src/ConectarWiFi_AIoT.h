#ifndef __SRC_CONECTARWIFI_AIOT_H__
#define __SRC_CONECTARWIFI_AIOT_H__

#include <Arduino.h>
#include <WiFi.h>

class WiFi_AIoT
{
private:
    void WiFi_Manager(void);
    void WiFi_Multi(void);

public:
    WiFi_AIoT();
    ~WiFi_AIoT();
    void ResetWiFi_AIoT(void);
    void DisconnectWiFi_AIoT(void);
    void ConectarWiFi_AIoT(int);

    String get_AIoT_SSID(void);
    String get_AIoT_PWD(void);

    String get_AIoT_IP(void);
    String get_AIoT_DNS(void);
    String get_AIoT_MAC(void);

    wl_status_t get_AIoT_status(void);
};

#endif // __SRC_CONECTARWIFI_AIOT_H__

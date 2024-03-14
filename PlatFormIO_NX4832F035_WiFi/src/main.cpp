//*************************************************************************************************//
//*************************************************************************************************//
// Universidad Distrital Francisco José de Caldas
// Facultad Tecnológica | Tecnología en Construcciones Civiles
// Maestria en Ingenieria Civil | 2024-I | Ernesto J. Guerrero G. | ejguerrerog@udistrital.edu.co
// Monitoreo AIoT
// Microcontroladores.: NodeMCU ESP32
//*************************************************************************************************//
//*************************************************************************************************//
// Iteadlib Arduino Nextion Library
// https://github.com/itead/ITEADLIB_Arduino_Nextion/
// Nextion, Iteadlib y ESP32: – Distribución Nextion
// https://nextion.ca/portfolio-items/nextion-iteadlib-and-esp32-step-by-step/
//*************************************************************************************************//
//*************************************************************************************************//
#include <Arduino.h>
#include "Nextion.h"
#define PinLED 2

unsigned long asyncDelay = 0;
int delayLength = 5000;

#include <WiFi.h>
String    SSIDname      = "NoName";
String    SSIDpassword  = "NoPassword";
uint16_t  SSIDcontador  = 0;
uint16_t  NCont         = 0;

/*
 * Declare a page object [page id:0,component id:1, component name: "b0"]. 
 */
NexPage     page0    =  NexPage(0,  0, "page0");
NexPage     page1    =  NexPage(1,  0, "page1");
NexPage     page2    =  NexPage(2,  0, "page2");

/*
 * Declare a button object [page id:0,component id:1, component name: "b0"]. 
 */
NexButton   page0_b0 =  NexButton(0,  1, "b0");

NexButton   page1_b0 =  NexButton(1,  1, "b0");
NexButton   page1_b1 =  NexButton(1,  2, "b1");
NexButton   page1_b2 =  NexButton(1,  4, "b2");
NexButton   page1_b3 =  NexButton(1,  3, "b3");
NexButton   page1_b4 =  NexButton(1,  7, "b4");
NexButton   page1_b5 =  NexButton(1,  8, "b5");
NexButton   page1_b7 =  NexButton(1, 10, "b7");
NexButton   page1_b8 =  NexButton(1, 11, "b8");

NexButton   page2_b0 =  NexButton(2,  1, "b0");
NexButton   page2_b1 =  NexButton(2,  2, "b1");
NexButton   page2_b4 =  NexButton(2,  5, "b4");
NexButton   page2_b5 =  NexButton(2,  6, "b5");

/*
 * Declare a text object [page id:0,component id:1, component name: "t0"]. 
 */
NexText     page1_t0 =  NexText(1,  5, "t0");
NexText     page1_t1 =  NexText(1,  6, "t1");
NexText     page1_t2 =  NexText(1,  9, "t2");

NexText     page2_t0 =  NexText(2,  3, "t0");
NexText     page2_t1 =  NexText(2,  4, "t1");
NexText     page2_t2 =  NexText(2,  12, "t2");
NexText     page2_t3 =  NexText(2,  13, "t3");
NexText     page2_t4 =  NexText(2,  14, "t4");
NexText     page2_t5 =  NexText(2,  15, "t5");
NexText     page2_t6 =  NexText(2,  16, "t6");
NexText     page2_t7 =  NexText(2,  17, "t7");

/*
 * Declare a dual state button object [page id:0,component id:1, component name: "bt0"]. 
 */
NexDSButton page1_bt0 = NexDSButton(1, 12, "bt0");

/*
 * Declare a slider object [page id:0,component id:1, component name: "t0"]. 
 */
NexSlider   page1_h0 =  NexSlider(1, 15, "h0");
NexSlider   page2_h0 =  NexSlider(1,  9, "h0");

/*
 * Declare a radio object [page id:0,component id:1, component name: "t0"]. 
 */
NexRadio    page1_r0 =  NexRadio(1, 14, "r0");
NexRadio    page2_r0 =  NexRadio(2,  8, "r0");

char buffer[100] = {0};

NexTouch *nex_listen_list[] = 
{
  &page0,
  &page1,
  &page2,

  &page0_b0,
  &page1_b0,
  &page1_b1,
  &page1_b2,
  &page1_b3,
  &page1_b4,
  &page1_b5,
  &page1_b7,
  &page1_b8,
  &page2_b0,
  &page2_b1,
  &page2_b4,
  &page2_b5,

  &page1_t0,
  &page1_t1,
  &page1_t2,
  &page2_t0,
  &page2_t1,
  &page2_t2,
  &page2_t3,
  &page2_t4,
  &page2_t5,
  &page2_t6,
  &page2_t7,

  &page1_bt0,

  &page1_h0,
  &page2_h0,

  &page1_r0,
  &page2_r0,

  NULL
};

//*************************************************************************************************//
//*************************************************************************************************//
void page0PopCallback(void*);
void page1PopCallback(void*);
void page2PopCallback(void*);

void page0_b0PopCallback(void*);
void page1_b0PopCallback(void*);
void page1_b1PopCallback(void*);
void page1_b2PopCallback(void*);
void page1_b3PopCallback(void*);
void page1_b4PopCallback(void*);
void page1_b5PopCallback(void*);
void page1_b7PopCallback(void*);
void page1_b8PopCallback(void*);
void page2_b0PopCallback(void*);
void page2_b1PopCallback(void*);
void page2_b4PopCallback(void*);
void page2_b5PopCallback(void*);

void page1_t0PopCallback(void*);
void page1_t1PopCallback(void*);
void page1_t2PopCallback(void*);
void page2_t0PopCallback(void*);
void page2_t1PopCallback(void*);
void page2_t2PopCallback(void*);
void page2_t3PopCallback(void*);
void page2_t4PopCallback(void*);
void page2_t5PopCallback(void*);
void page2_t6PopCallback(void*);
void page2_t7PopCallback(void*);

void page1_bt0PopCallback(void*);

void page1_h0PopCallback(void*);
void page2_h0PopCallback(void*);

void page1_r0PopCallback(void*);
void page2_r0PopCallback(void*);

void WiFi_Init(void);
void delayFunction(void);

//*************************************************************************************************//
//*************************************************************************************************//
void setup() {
  nexInit();
  dbSerialPrintln("setup begin");
  pinMode (PinLED, OUTPUT);
  page0.attachPop(page0PopCallback);
  page1.attachPop(page1PopCallback);
  page2.attachPop(page2PopCallback);
  
  page1_b2.attachPop(page1_b2PopCallback, &page1_b2);
  page1_b3.attachPop(page1_b3PopCallback, &page1_b3);
  page1_b7.attachPop(page1_b7PopCallback, &page1_b7);
  page1_b8.attachPop(page1_b8PopCallback, &page1_b8);
  page1_bt0.attachPop(page1_bt0PopCallback, &page1_bt0);
  page1_t0.attachPop(page1_t0PopCallback);
  page1_t2.attachPop(page1_t2PopCallback);
  page1_r0.attachPop(page1_r0PopCallback);
    
  page2_t4.attachPop(page2_t4PopCallback);
  page2_t5.attachPop(page2_t5PopCallback);
  page2_t6.attachPop(page2_t6PopCallback);
  page2_t7.attachPop(page2_t7PopCallback);
  page2_r0.attachPop(page2_r0PopCallback);
  dbSerialPrintln("setup done");
}

void loop() {
  nexLoop(nex_listen_list);
  
  // NOTE : ASYNC DELAY
  // NOTA : RETARDO ASÍNCRO
  if(millis() > asyncDelay) {
    asyncDelay+=delayLength;
    delayFunction();
  }
}

//*************************************************************************************************//
//*************************************************************************************************//

void page0PopCallback(void *ptr) {
    dbSerialPrintln("page0PopCallback");
    page0.show();
}

void page1PopCallback(void *ptr) {
    dbSerialPrintln("page1PopCallback");
    page1.show();
}

void page2PopCallback(void *ptr) {
    dbSerialPrintln("page2PopCallback");
    page2.show();
}

void page0_b0PopCallback(void *ptr) {
  dbSerialPrintln("page0_b0PopCallback");
}

void page1_b0PopCallback(void *ptr) {
  dbSerialPrintln("page1_b0PopCallback");
}

void page1_b1PopCallback(void *ptr) {
  dbSerialPrintln("page1_b1PopCallback");
}

void page1_b2PopCallback(void *ptr) {
  WiFi_Init();
  dbSerialPrintln("page1_b2PopCallback.: (Re-Scan)");
  page1_bt0.setText("SCANNING...");
  page1_t0.setText("WiFi SSID");
  dbSerialPrintln("==============================================================================");
  dbSerialPrintln("Start Scanning");
  int n = WiFi.scanNetworks();
  SSIDcontador = n - 1;
  NCont = 0;
  if(n == 0) {
    dbSerialPrintln("No Networks Found");
  }
  else {
    for(int i = 0; i < n; ++i) {
      dbSerialPrintln(WiFi.SSID(i));
    }
    page1_bt0.setText(WiFi.SSID(0).c_str());
    page1_t0.setText("WiFi SSID (0)");
  }
  dbSerialPrintln("Scanning Completed");
  dbSerialPrintln("==============================================================================");
}

void page1_b3PopCallback(void *ptr) {
  dbSerialPrintln("page1_b3PopCallback.: (Connect)");
  memset(buffer, 0, sizeof(buffer));
  page1_bt0.getText(buffer, sizeof(buffer));
  SSIDname = buffer;
  dbSerialPrintln(SSIDname);

  memset(buffer, 0, sizeof(buffer));
  page1_t2.getText(buffer, sizeof(buffer));
  SSIDpassword = buffer;
  dbSerialPrintln(SSIDpassword);

  dbSerialPrintln("==============================================================================");
  WiFi.begin(SSIDname.c_str(),SSIDpassword.c_str());
  dbSerialPrintln("Dirección IP   .: " + WiFi.localIP().toString());
}

void page1_b4PopCallback(void *ptr) {
  dbSerialPrintln("page1_b4PopCallback");
}

void page1_b5PopCallback(void *ptr) {
  dbSerialPrintln("page1_b5PopCallback");
}

void page1_b7PopCallback(void *ptr) {
  dbSerialPrintln("page1_b7PopCallback");  
  if(NCont < SSIDcontador) {
    NCont += 1;    
  } else {
    NCont = 0;
  }  
  dbSerialPrintln("==============================================================================");
  dbSerialPrintln("SSIDcontador .: " + String(SSIDcontador));

  String  valor_page1_t0 = "WiFi SSID (" + String(NCont) + ")";
  page1_t0.setText(valor_page1_t0.c_str());
  page1_bt0.setText(WiFi.SSID(NCont).c_str());
}

void page1_b8PopCallback(void *ptr) {
  dbSerialPrintln("page1_b8PopCallback");  
  if(NCont > 0) {
    NCont -= 1;  
  } else {
    NCont = SSIDcontador;
  }
  dbSerialPrintln("==============================================================================");
  dbSerialPrintln("SSIDcontador .: " + String(SSIDcontador));

  String  valor_page1_t0 = "WiFi SSID (" + String(NCont) + ")";
  page1_t0.setText(valor_page1_t0.c_str());
  page1_bt0.setText(WiFi.SSID(NCont).c_str());
}

void page2_b0PopCallback(void *ptr) {
  dbSerialPrintln("page2_b0PopCallback");
}

void page2_b1PopCallback(void *ptr) {
  dbSerialPrintln("page2_b1PopCallback");
}

void page2_b4PopCallback(void *ptr) {
  dbSerialPrintln("page2_b4PopCallback");
}

void page2_b5PopCallback(void *ptr) {
  dbSerialPrintln("page2_b5PopCallback");
}
							   
void page1_t0PopCallback(void *ptr) {
  dbSerialPrintln("page1_t0PopCallback");
}

void page1_t1PopCallback(void *ptr) {
  dbSerialPrintln("page1_t1PopCallback");
}

void page1_t2PopCallback(void *ptr) {
  dbSerialPrintln("page1_t2PopCallback");
}

void page2_t0PopCallback(void *ptr) {
  dbSerialPrintln("page2_t0PopCallback");
}

void page2_t1PopCallback(void *ptr) {
  dbSerialPrintln("page2_t1PopCallback");
}

void page2_t2PopCallback(void *ptr) {
  dbSerialPrintln("page2_t2PopCallback");
}

void page2_t3PopCallback(void *ptr) {
  dbSerialPrintln("page2_t3PopCallback");
}

void page2_t4PopCallback(void *ptr) {
  dbSerialPrintln("page2_t4PopCallback");
}

void page2_t5PopCallback(void *ptr) {
  dbSerialPrintln("page2_t5PopCallback");
}

void page2_t6PopCallback(void *ptr) {
  dbSerialPrintln("page2_t6PopCallback");
}

void page2_t7PopCallback(void *ptr) {
  dbSerialPrintln("page2_t7PopCallback");
}

void page1_bt0PopCallback(void *ptr) {
  dbSerialPrintln("page1_bt0PopCallback");
}

void page1_h0PopCallback(void *ptr) {
  dbSerialPrintln("page1_h0PopCallback");
}

void page2_h0PopCallback(void *ptr) {
  dbSerialPrintln("page2_h0PopCallback");
}

void page1_r0PopCallback(void *ptr) {
  dbSerialPrintln("page1_r0PopCallback");
}

void page2_r0PopCallback(void *ptr) {
  dbSerialPrintln("page2_r0PopCallback");
}

/**
 * @brief Initialize the WiFi mode to station mode and disconnect if connected
 * @param  none
 */
void WiFi_Init(void) {
  WiFi.mode(WIFI_STA);  
  WiFi.disconnect();
}

void delayFunction(void) {
  digitalWrite(PinLED, !digitalRead(PinLED));
  // NOTE : STUFF HERE
  dbSerialPrintln("==============================================================================");
  dbSerialPrintln(SSIDname + " : " + SSIDpassword);
  dbSerialPrintln("Conectado a la red WiFi.: " + WiFi.SSID());
  dbSerialPrintln("WiFi STATUS     .: " + String(WiFi.status()));
  // 266:	  WL_NO_SHIELD
  // 0:	  	WL_IDLE_STATUS 
  // 1:	  	WL_NO_SSID_AVAIL
  // 2:	  	WL_SCAN_COMPLETED
  // 3:	  	WL_CONNECTED
  // 4:	  	WL_CONNECT_FAILED
  // 5:   	WL_CONNECTION_LOST
  // 6:	  	WL_DISCONNECTED
  // if(WiFi.status == something)
  dbSerialPrintln("Dirección IP    .: " + WiFi.localIP().toString());
  dbSerialPrintln("Dirección DNS   .: " + WiFi.dnsIP().toString());
  dbSerialPrintln("Dirección MAC   .: " + WiFi.macAddress());
  if(WiFi.status() == 3) {
    // Page 1
    page1_r0.Set_font_color_pco(1024);
    page1_r0.Set_background_color_bco(1024);
    // Page 2
    page2_r0.Set_font_color_pco(1024);
    page2_r0.Set_background_color_bco(1024);
    // SSID, IP, DNS, MAC
    page2_t4.setText(WiFi.SSID().c_str());                // SSID.
    page2_t5.setText(WiFi.localIP().toString().c_str());  // IP.
    page2_t6.setText(WiFi.dnsIP().toString().c_str());    // DNS.
    page2_t7.setText(WiFi.macAddress().c_str());          // MAC.
  }
  else {
    // Page 1
    page1_r0.Set_font_color_pco(63488);
    page1_r0.Set_background_color_bco(63488);
    // Page 2
    page2_r0.Set_font_color_pco(63488);
    page2_r0.Set_background_color_bco(63488);
    // SSID, IP, DNS, MAC
    page2_t4.setText("SSID");               //SSID.
    page2_t5.setText("xxx:xxx:xxx:xxx");    //IP.
    page2_t6.setText("xxx:xxx:xxx:xxx");    //DNS.
    page2_t7.setText("xx:xx:xx:xx:xx:xx");  //MAC.
  }
}
//*************************************************************************************************//
//*************************************************************************************************//
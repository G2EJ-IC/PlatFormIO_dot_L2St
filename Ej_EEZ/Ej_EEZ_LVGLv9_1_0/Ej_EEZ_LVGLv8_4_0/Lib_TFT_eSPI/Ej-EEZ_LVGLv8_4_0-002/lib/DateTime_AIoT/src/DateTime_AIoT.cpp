// LIBRERIA DE ARDUINO.
#include <Arduino.h>
#include <DateTime_AIoT.h>

  dhms_AIoT::dhms_AIoT(){};
  dhms_AIoT::~dhms_AIoT(){};

/* =============================icache functions========================= */

String dhms_AIoT::DHMS_AIoT_get(unsigned long long mSegT) {
  char DHMS[25];

  int SubSEG = mSegT % 1000ULL; // 1000ULL
  int SegT = mSegT / 1000ULL; // 1000ULL

  int DIA = SegT / 86400; // 60*60*24
  SegT %= 86400; //60*60*24

  int HORA = SegT / 3600; // 1000*60*60
  SegT %= 3600; // 1000*60*60

  int MINUTO = SegT / 60; // 60
  SegT %= 60; // 60
  int SEG = SegT;

  if (DIA == 0 && HORA == 0 && MINUTO == 0) {
    sprintf(DHMS,"%.2d.%.2ds", 
      SEG, SubSEG); 
  } else if (DIA == 0 && HORA == 0) {
    sprintf(DHMS,"%.2dm %.2d.%.2ds", 
      MINUTO, SEG, SubSEG); 
  } else if (DIA == 0) {
    sprintf(DHMS,"%.2dh %.2dm %.2d.%.2ds",
      HORA, MINUTO, SEG, SubSEG); 
  } else {
    sprintf(DHMS,"%dd %.2dh %.2dm %.2d.%.2ds",
      DIA, HORA, MINUTO, SEG, SubSEG); 
  }
  return String(DHMS);
}
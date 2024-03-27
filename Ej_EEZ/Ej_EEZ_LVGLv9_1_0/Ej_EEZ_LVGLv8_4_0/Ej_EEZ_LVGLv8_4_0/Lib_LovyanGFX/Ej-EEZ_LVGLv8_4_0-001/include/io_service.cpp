#include <Arduino.h>
#include "io_service.h"
#include "screens.h"

io_service::io_service() {}
io_service::~io_service() {}

/* =============================icache functions========================= */
void ICACHE_FLASH_ATTR io_service::setup()
{
  //lv_obj_clear_flag(objects.ui_panel_conectar_wi_fi, LV_OBJ_FLAG_HIDDEN);
} // end io setup

void ICACHE_FLASH_ATTR io_service::loop()
{

} // end io loop
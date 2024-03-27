#ifndef __IO_SERVICE_H__
#define __IO_SERVICE_H__

#define ICACHE_FLASH_ATTR

class io_service
{
private:
    friend class display_service;
    // friend class io_service;
    friend class tp_service;

public:
    io_service();
    ~io_service();

    void ICACHE_FLASH_ATTR ParpadeoLED(void);
    void ICACHE_FLASH_ATTR TestHWM(const char *, uint32_t);
    void ICACHE_FLASH_ATTR memoria_ESP(void);
    void ICACHE_FLASH_ATTR feedTheDog(void);
    void ICACHE_FLASH_ATTR setup();
    void ICACHE_FLASH_ATTR loop();
    void ICACHE_FLASH_ATTR cronometro(uint32_t); 
};

#endif // __IO_SERVICE_H__
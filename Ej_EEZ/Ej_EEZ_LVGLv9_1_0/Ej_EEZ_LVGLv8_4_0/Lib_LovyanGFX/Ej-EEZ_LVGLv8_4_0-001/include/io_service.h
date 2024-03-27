#ifndef __IO_SERVICE_H__
#define __IO_SERVICE_H__

#define ICACHE_FLASH_ATTR

class io_service
{
private:
public:
    io_service();
    ~io_service();

    void ICACHE_FLASH_ATTR setup();
    void ICACHE_FLASH_ATTR loop();
};

#endif // __IO_SERVICE_H__
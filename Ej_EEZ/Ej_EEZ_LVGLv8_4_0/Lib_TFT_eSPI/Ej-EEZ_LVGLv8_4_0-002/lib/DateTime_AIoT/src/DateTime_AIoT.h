#ifndef __DATETIME_AIOT_H__
#define __DATETIME_AIOT_H__

class dhms_AIoT
{
private:

public:
    dhms_AIoT();
    ~dhms_AIoT();

    String ICACHE_FLASH_ATTR DHMS_AIoT(unsigned long long);

    void ICACHE_FLASH_ATTR setup();
    void ICACHE_FLASH_ATTR loop();       
};

#endif // __DATETIME_AIOT_H__

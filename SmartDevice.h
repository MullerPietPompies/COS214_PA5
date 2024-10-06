#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H
#include <string>


class SmartDevice
{
private:
public:
    virtual std::string getStatus()=0;
    virtual void performAction(const std::string& action) = 0;
    virtual std::string getDeviceType()=0;
    virtual ~SmartDevice()=default;
};



#endif
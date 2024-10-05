#ifndef DOORLOCK_H
#define DOORLOCK_H

#include "SmartDevice.h"
#include <string>

class Doorlock : public SmartDevice
{
private:
    bool isLocked;
public:
    Doorlock();
    std::string getStatus() override;
    void performAction(const std::string& action) override;
    std::string getDeviceType() override;
};
#endif
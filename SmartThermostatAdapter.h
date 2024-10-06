#ifndef SMARTTHERMOSTATADAPTER_H
#define SMARTTHERMOSTATADAPTER_H

#include "SmartDevice.h"
class LegacyThermostat {
public:
    int getLegacyTemperature();
    void setLegacyTemperature(int temperature);
};

class SmartThermostatAdapter : public SmartDevice {
private:
    LegacyThermostat* legacyThermostat;
public:
    SmartThermostatAdapter(LegacyThermostat* thermostat);
    std::string getStatus() override;
    void performAction(const std::string& action) override;
    std::string getDeviceType() override;
};

#endif
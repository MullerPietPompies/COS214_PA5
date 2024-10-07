/**
 * @class Light
 * @brief A class representing a smart light device.
 * 
 * This class represents a smart light, which can be toggled
 * on or off as part of a smart home automation system.
 */

#ifndef LIGHT_H
#define LIGHT_H


#include <string>
#include "SmartDevice.h"

class Light : public SmartDevice{
    private:
        bool isOn; ///< Indicates whether the light is on or off.
    public:
        Light();
        std::string getStatus() override;
        void performAction(const std::string& action) override;
        std::string getDeviceType() override;
};

#endif
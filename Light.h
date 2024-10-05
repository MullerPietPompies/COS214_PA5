#ifndef LIGHT_H
#define LIGHT_H


#include <string>
#include "SmartDevice.h"

class Light : public SmartDevice{
    private:
        bool isOn;
    public:
        Light();
        std::string getStatus() override;
        void performAction(const std::string& action) override;
        std::string getDeviceType() override;
};

#endif
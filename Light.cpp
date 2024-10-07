#include "Light.h"

Light::Light() : isOn(false) {}

std::string Light::getStatus() {
    return isOn ? "On" : "Off";
}

void Light::performAction(const std::string& action) {
    if (action == "Toggle") {
        isOn = !isOn;
    }
}

std::string Light::getDeviceType() {
    return "Light";
}
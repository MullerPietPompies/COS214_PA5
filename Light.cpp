#include "Light.h"
/**
     * @brief Default constructor for the Light class.
     * 
     * Initializes the light in the off state.
 */
Light::Light() : isOn(false) {}
/**
     * @brief Get the current status of the light.
     * 
     * @return std::string - The current status, either "On" or "Off".
 */
std::string Light::getStatus() {
    return isOn ? "On" : "Off";
}
/**
     * @brief Perform an action to toggle the light's state.
     * 
     * @param action A string representing the action to perform (e.g., "Toggle").
 */
void Light::performAction(const std::string& action) {
    if (action == "Toggle") {
        isOn = !isOn;
    }
}
    /**
     * @brief Get the type of the device.
     *
     * @return std::string - The type of the device, which is "Light".
     */
std::string Light::getDeviceType() {
    return "Light";
}
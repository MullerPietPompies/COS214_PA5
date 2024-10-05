#include "SmartThermostatAdapter.h"

// LegacyThermostat Implementation
int LegacyThermostat::getLegacyTemperature() {
    return 20; // Just a sample value
}

void LegacyThermostat::setLegacyTemperature(int temperature) {
    // Implementation for setting temperature
}

// SmartThermostatAdapter Implementation
SmartThermostatAdapter::SmartThermostatAdapter(LegacyThermostat* thermostat)
    : legacyThermostat(thermostat) {}

std::string SmartThermostatAdapter::getStatus() {
    return "Temperature: " + std::to_string(legacyThermostat->getLegacyTemperature());
}

void SmartThermostatAdapter::performAction(const std::string& action) {
    // Implement mapping of new commands to legacy thermostat
}

std::string SmartThermostatAdapter::getDeviceType() {
    return "Thermostat";
}

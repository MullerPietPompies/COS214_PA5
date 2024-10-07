#include "Command.h"

// TurnOffAllLights Implementation
TurnOffAllLights::TurnOffAllLights(const std::vector<SmartDevice*>& devices) : devices(devices) {}

void TurnOffAllLights::execute() {
    for (auto device : devices) {
        if (device->getDeviceType() == "Light") {
            device->performAction("Toggle");
        }
    }
}

// LockAllDoors Implementation
LockAllDoors::LockAllDoors(const std::vector<SmartDevice*>& devices) : devices(devices) {}

void LockAllDoors::execute() {
    for (auto device : devices) {
        if (device->getDeviceType() == "DoorLock") {
            device->performAction("Toggle");
        }
    }
}

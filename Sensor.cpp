#include "Sensor.h"
#include <algorithm>

// Sensor Implementation
void Sensor::addDevice(Observer* device) {
    devices.push_back(device);
}

void Sensor::removeDevice(Observer* device) {
    devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
}

void Sensor::notifyDevices() {
    for (Observer* device : devices) {
        device->update();
    }
}

// MotionSensor Implementation
MotionSensor::MotionSensor(SmartDevice* light) : light(light) {}

void MotionSensor::update() {
    light->performAction("Toggle");
}

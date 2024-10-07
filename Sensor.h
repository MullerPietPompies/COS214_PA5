#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include "SmartDevice.h"

// Observer Interface
class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};

// Sensor Class (Subject)
class Sensor {
private:
    std::vector<Observer*> devices;
public:
    void addDevice(Observer* device);
    void removeDevice(Observer* device);
    void notifyDevices();
};

// MotionSensor (Observer that turns on the light when triggered)
class MotionSensor : public Observer {
private:
    SmartDevice* light;
public:
    MotionSensor(SmartDevice* light);
    void update() override;
};

#endif // SENSOR_H

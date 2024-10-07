// #include <iostream>
// #include "SmartDevice.h"
// #include "SmartThermostatAdapter.h"
// #include "Command.h"
// #include "Sensor.h"
// #include "Light.h"
// #include "Doorlock.h"

// int main() {
//     // Create some devices
//     Light livingRoomLight;
//     Doorlock frontDoor;

//     // Legacy Thermostat Integration
//     LegacyThermostat oldThermostat;
//     SmartThermostatAdapter smartThermostat(&oldThermostat);

//     // Commands for automation
//     std::vector<SmartDevice*> devices = { &livingRoomLight, &frontDoor, &smartThermostat };
//     TurnOffAllLights turnOffLights(devices);
//     LockAllDoors lockDoors(devices);

//     // Execute automation commands
//     turnOffLights.execute();
//     lockDoors.execute();

//     // Observer pattern
//     MotionSensor motionSensor(&livingRoomLight);
//     Sensor sensor;
//     sensor.addDevice(&motionSensor);

//     // Simulate motion detection
//     std::cout << "Motion detected!" << std::endl;
//     sensor.notifyDevices();

//     return 0;
// }

#include <iostream>
#include "SmartDevice.h"
#include "SmartThermostatAdapter.h"
#include "Command.h"
#include "Sensor.h"
#include "Light.h"
#include "Doorlock.h"

// Helper function for testing
void testResult(const std::string& testName, bool result) {
    if (result) {
        std::cout << "[PASS] " << testName << std::endl;
    } else {
        std::cout << "[FAIL] " << testName << std::endl;
    }
}

int main() {
    // Testing individual device behavior (Unit Tests)
    std::cout << "Running Unit Tests..." << std::endl;

    // Test Light functionality
    Light livingRoomLight;
    testResult("Light initial state (Off)", livingRoomLight.getStatus() == "Off");

    livingRoomLight.performAction("Toggle");
    testResult("Light state after toggle (On)", livingRoomLight.getStatus() == "On");

    livingRoomLight.performAction("Toggle");
    testResult("Light state after second toggle (Off)", livingRoomLight.getStatus() == "Off");

    // Test DoorLock functionality
    Doorlock frontDoor;
    testResult("DoorLock initial state (Locked)", frontDoor.getStatus() == "Locked");

    frontDoor.performAction("Toggle");
    testResult("DoorLock state after toggle (Unlocked)", frontDoor.getStatus() == "Unlocked");

    frontDoor.performAction("Toggle");
    testResult("DoorLock state after second toggle (Locked)", frontDoor.getStatus() == "Locked");

    // Test LegacyThermostat integration via adapter
    LegacyThermostat oldThermostat;
    SmartThermostatAdapter smartThermostat(&oldThermostat);
    testResult("SmartThermostat initial temperature", smartThermostat.getStatus() == "Temperature: 20");

    // Testing automation with commands (Integration Tests)
    std::cout << "Running Integration Tests..." << std::endl;

    // Prepare multiple devices
    Light bedroomLight;
    Doorlock garageDoor;
    std::vector<SmartDevice*> devices = { &livingRoomLight, &bedroomLight, &frontDoor, &garageDoor };

    // Create command to turn off all lights
    TurnOffAllLights turnOffAllLights(devices);
    
    // Turn on lights for testing
    livingRoomLight.performAction("Toggle");
    bedroomLight.performAction("Toggle");

    turnOffAllLights.execute();
    testResult("LivingRoomLight after TurnOffAllLights", livingRoomLight.getStatus() == "Off");
    testResult("BedroomLight after TurnOffAllLights", bedroomLight.getStatus() == "Off");

    // Create command to lock all doors
    LockAllDoors lockAllDoors(devices);

    frontDoor.performAction("Toggle"); // Unlock for testing
    garageDoor.performAction("Toggle"); // Unlock for testing

    lockAllDoors.execute();
    testResult("FrontDoor after LockAllDoors", frontDoor.getStatus() == "Locked");
    testResult("GarageDoor after LockAllDoors", garageDoor.getStatus() == "Locked");

    // Testing observer pattern (Integration Test)
    std::cout << "Testing Motion Sensor..." << std::endl;
    MotionSensor motionSensor(&livingRoomLight);
    Sensor sensor;
    sensor.addDevice(&motionSensor);

    // Light should be off initially
    testResult("Light initial state before sensor trigger", livingRoomLight.getStatus() == "Off");

    // Trigger sensor (motion detected)
    sensor.notifyDevices();
    testResult("Light state after sensor triggers", livingRoomLight.getStatus() == "On");

    // Trigger sensor again
    sensor.notifyDevices();
    testResult("Light state after second sensor trigger", livingRoomLight.getStatus() == "Off");

    return 0;
}

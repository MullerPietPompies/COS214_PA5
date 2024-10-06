#include "Doorlock.h"

Doorlock::Doorlock() : isLocked(true) {}

std::string Doorlock::getStatus() {
    return isLocked ? "Locked" : "Unlocked";
}

void Doorlock::performAction(const std::string& action) {
    if (action == "Toggle") {
        isLocked = !isLocked;
    }
}

std::string Doorlock::getDeviceType() {
    return "DoorLock";
}
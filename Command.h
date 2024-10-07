#ifndef COMMAND_H
#define COMMAND_H

#include <vector>
#include "SmartDevice.h"

// Command Interface
class Command {
public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

// TurnOffAllLights Command
class TurnOffAllLights : public Command {
private:
    std::vector<SmartDevice*> devices;
public:
    TurnOffAllLights(const std::vector<SmartDevice*>& devices);
    void execute() override;
};

// LockAllDoors Command
class LockAllDoors : public Command {
private:
    std::vector<SmartDevice*> devices;
public:
    LockAllDoors(const std::vector<SmartDevice*>& devices);
    void execute() override;
};

#endif // COMMAND_H

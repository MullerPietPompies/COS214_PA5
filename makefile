# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

# Executable name
EXEC = prac5.out

# Source files
SOURCES = Command.cpp Doorlock.cpp Light.cpp Sensor.cpp SmartDevice.cpp SmartThermostatAdapter.cpp TestingMain.cpp
# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(EXEC)

# Link object files to create executable
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJECTS) $(EXEC)

# Run the executable
run: $(EXEC)
	./$(EXEC)

# Phony targets
.PHONY: all clean run
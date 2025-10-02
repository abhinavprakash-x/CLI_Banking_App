# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -o

# Target executable
TARGET = main.exe

# Source files
SRCS = main.cpp customer.cpp admin.cpp

# Default rule to build and run the executable
all:
	$(CXX) $(SRCS) $(CXXFLAGS) $(TARGET)
	$(TARGET)	
# Adapted from: https://makefiletutorial.com/

# compiler
CC := g++

# target executable
TARGET_EXEC := raytracer

# source and build directory
BUILD_DIR := ./build
SRC_DIRS := ./src

# source files and object files
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)

# include directories and flags
INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

# compiler flags
CFLAGE :=
CPPFLAGS := -g $(INC_FLAGS)

# The final build step.
./$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

# Build step for C++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -fr ./build
	rm -f ./$(TARGET_EXEC)
CXX = g++
# Compilation flags
CXXFLAGS = -Wall -g

# Target executable
TARGET = greedy_algorithm

# Source files
SRCS = greedy_algorithm.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Rule to link the object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -f $(TARGET) $(OBJS)

# Phony targets to prevent conflicts with files named 'all' or 'clean'
.PHONY: all clean
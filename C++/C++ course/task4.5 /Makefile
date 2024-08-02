
CXX = g++

CXXFLAGS = -std=c++17 -Wall -Wextra -Werror


TARGET = task_4_5


OBJS = main.o Car.o


all: $(TARGET)


$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)


main.o: main.cpp Car.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Car.o: Car.cpp Car.h
	$(CXX) $(CXXFLAGS) -c Car.cpp


clean:
	rm -f $(OBJS) $(TARGET)

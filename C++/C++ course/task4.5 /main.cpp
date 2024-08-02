#include "Car.h"
#include <iostream>

int main() 
{
    Car car("Bugatti", 2006, 200000, 120, Car::Color::BLACK);
    std::cout << car.toString() << std::endl;

    return 0;
}

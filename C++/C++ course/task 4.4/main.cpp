#include "Car.h"
#include <iostream>

int main() 
{
    Car car;
    
    car.setPrice(200);
    car.setModel("Nissan");
    car.setCurrentFuelVolume(40);
    car.setYearOfProduction(2006);
    car.setTankVolume(60);
    car.setColor(Car::Color::BLACK);

    std::cout << car.toString() << std::endl;
    car.canDrive(1);
    car.refuel(10);
    std::cout << car.isTankFull() << std::endl;
      car.refuel(10, 5);
    return 0;
}

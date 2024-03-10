#include <iostream>
#include "car.h"
using namespace std;
int main()
{
    car car;
    {
        car.setPrice(200);
        car.setModel("Nissan");
        car.setCurrentFuelVolume(590);
        car.setYearOfProduction(2006);
        car.setTankVolume(15.0);
       
    }
    
}

#include "Car.h"
#include <iostream>

std::string Car::getModel() 
{
    return m_Model;
}

void Car::setModel(const std::string &_model) 
{
    m_Model = _model;
}

unsigned int Car::getYearOfProduction() 
{
    return m_YearOfProduction;
}

void Car::setYearOfProduction(unsigned int _YearOfProduction) 
{
    m_YearOfProduction = _YearOfProduction;
}

int Car::getPrice() 
{
    return m_Price;
}

void Car::setPrice(int _price) 
{
    m_Price = _price;
}

Car::Color Car::getColor() 
{
    return m_color;
};

void Car::setColor(Car::Color _color) 
{
    m_color = _color;
}

int Car::getTankVolume() 
{
    return m_TankVolume;
}

void Car::setTankVolume(int _TankVolume) 
{
    m_TankVolume = _TankVolume;
}

double Car::getCurrentFuelVolume()
{
    return m_CurrentFuelVolume;
}

void Car::setCurrentFuelVolume(double _CurrentFuelVolume) 
{
    m_CurrentFuelVolume = _CurrentFuelVolume;
}

std::string Car::toString() {
    std::string result = "Model:" + m_Model +  ", YearOfProduction:" + std::to_string(m_YearOfProduction)  + ", Price:" + std::to_string(m_Price) + ", TankVolume:" +
          std::to_string(m_TankVolume) + ", CurrentFuelVolume:" + std::to_string(m_CurrentFuelVolume) + ", Color:" + std::to_string(static_cast<int>(m_color));
    return result;
}

std::pair<bool, double> Car::canDrive(unsigned int _distance) 
{
    std::pair<bool, double> result;
    result.second = _distance / 20.0;
    result.first = m_CurrentFuelVolume - result.second >= 0;
    return result;
}

void Car::refuel(unsigned int volume) 
{
    if (m_CurrentFuelVolume + volume <= m_TankVolume) 
    {
        m_CurrentFuelVolume += volume;
        std::cout << "додано об'єм " << volume << std::endl;
    } 
    else 
    {
        std::cout << "У вас недостатньо об'єму палива" << std::endl;
    }
}

void Car::refuel(unsigned int volume, unsigned int price)
{
  if (m_CurrentFuelVolume + volume <= m_TankVolume && volume <= price)
  {
    m_CurrentFuelVolume += volume;
    std::cout << "додано об'єм " << volume << std::endl;
  }
  else
  {
    std::cout << "У вас недостатньо об'єму палива" << std::endl;
  }
}

bool Car::isTankFull() 
{
    return m_CurrentFuelVolume == m_TankVolume;
}

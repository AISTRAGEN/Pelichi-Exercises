#include "car.h"

std::string car::getModel() 
{ 
  return m_Model; 
}

void car::setModel(const std::string &_model) 
{ 
  m_Model = _model; 
}

unsigned int car::getYearOfProduction() 
{ 
  return m_YearOfProduction; 
}

void car::setYearOfProduction(unsigned int _YearOfProduction) 
{
  m_YearOfProduction = _YearOfProduction;
}

int car::getPrice() 
{ 
  return m_Price; 
}

void car::setPrice(int _price) 
{ 
  m_Price = _price; 
}

int car::getTankVolume() 
{ 
  return m_TankVolume; 
}

void car::setTankVolume(int _TankVolume) 
{ 
  m_TankVolume = _TankVolume; 
}

double car::getCurrentFuelVolume() 
{ 
  return m_CurrentFuelVolume; 
}

void car::setCurrentFuelVolume(double _CurrentFuelVolume) 
{
  m_CurrentFuelVolume = _CurrentFuelVolume;
}


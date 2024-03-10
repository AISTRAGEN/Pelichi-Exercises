

#ifndef INC_4_3_CAR_H
#define INC_4_3_CAR_H

#endif // INC_4_3_CAR_H

#ifndef INC_4_2P_CAR_H
#define INC_4_2P_CAR_H
#include <iostream>
#include <string>
using namespace std;

class Car {
public:
  enum class Color { WHITE, BLACK, YELLOW, GREEN };

public:
  string getModel();
  void setModel(const string &_model);

  unsigned int getYearOfProduction();
  void setYearOfProduction(unsigned int _YearOfProduction);

  int getPrice();
  void setPrice(int _price);

  int getTankVolume();
  void setTankVolume(int _TankVolume);

  double getCurrentFuelVolume();
  void setCurrentFuelVolume(double _CurrentFuelVolume);

  Color getColor();
  void setColor(Color _color);

  string toString();
  pair<bool, double> canDrive(unsigned int distance);

  void refuel(unsigned int volume);

  bool isTankFull();

private:
  string m_Model;
  unsigned int m_YearOfProduction;
  Color m_color;
  int m_Price;
  int m_TankVolume;
  double m_CurrentFuelVolume;
};

#endif // INC_4_2P_CAR_H

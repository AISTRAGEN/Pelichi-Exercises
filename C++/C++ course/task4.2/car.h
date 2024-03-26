
#ifndef INC_4_2P_CAR_H
#define INC_4_2P_CAR_H
#include <string>


class car 
{
public:
  enum class color { WHITE, BLACK, YELLOW, GREEN };

public:
  std::string getModel();
  void setModel(const std::string &_model);

  unsigned int getYearOfProduction();
  void setYearOfProduction(unsigned int _YearOfProduction);

  int getPrice();
  void setPrice(int _price);

  int getTankVolume();
  void setTankVolume(int _TankVolume);

  double getCurrentFuelVolume();
  void setCurrentFuelVolume(double _CurrentFuelVolume);

private:
  std::string m_Model;
  unsigned int m_YearOfProduction;
  int m_Price;
  int m_TankVolume;
  double m_CurrentFuelVolume;
};

#endif // INC_4_2P_CAR_H

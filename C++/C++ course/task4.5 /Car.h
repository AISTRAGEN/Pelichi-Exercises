
#ifndef INC_4_2P_CAR_H
#define INC_4_2P_CAR_H

#include <string>
#include <iostream>

class Car 
{
public:
    enum class Color 
    {
        WHITE,
        BLACK,
        YELLOW,
        GREEN
    };

   Car(std::string _model, unsigned int _YearOfProduction, unsigned int _price, int _TankVolume, Color _color);
  ~Car();
    std::string getModel();
    void setModel(const std::string& _model);

    unsigned int getYearOfProduction();

    int getPrice();
    void setPrice(int _price);

    int getTankVolume();

    double getCurrentFuelVolume();
    void setCurrentFuelVolume(double _CurrentFuelVolume);

    Color getColor();
    void setColor(Color _color);

    std::string toString();
    std::pair<bool, double> canDrive(unsigned int distance);

    void refuel(unsigned int volume);
    void refuel(unsigned int volume, unsigned int price);

    bool isTankFull();

private:
    std::string m_Model;
    unsigned int m_YearOfProduction;
    Color m_color;
    int m_Price;
    int m_TankVolume;
    double m_CurrentFuelVolume;
};

#endif //INC_4_2P_CAR_H

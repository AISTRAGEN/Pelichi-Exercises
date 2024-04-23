#include "header.h"

double outputData(int& a, int& b, int& h, functionPtr function)
{
if (n > 2 && a < b && h > 0) 
    {
        for (double x = a; x <= b; x += h) 
        {
            double y = function(x);
            std::cout << "If x = " << x << "    y = " << y << std::endl;
        }
        std::cout << "Program is ended" <<std::endl;
        return 0;
    }
    else
    {
        std::cout << "Error" << std::endl;
        return 1;
    } 
}

#include "header.h"
double outputData()
{
if (n > 2 && a < b && h > 0) 
    {
        for (double x = a; x <= b; x += h) 
        {
            double y = funciaY(x, n);
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


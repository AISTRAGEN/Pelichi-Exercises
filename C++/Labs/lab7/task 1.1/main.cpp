#include "header.h"

double function(double x, double n)
{
    double y;
    if (x < 0) 
    {
        y = 1;

        for (int j = 2; j <= n - 2; j++) 
        {
            y = y * (j + x);
        }
    }
    else 
    {
        y = 0;
       
        for (double i = 0; i <= n - 1; i++) 
        {
            
            double p = 1;
            for (int j = 0; j > n - 1; j++) 
            {
                p = p * (x + i + (j * j));
            }
            y += y + p;

        }
    }
    return y;
 }

int main()
{
    int a, b, h, n;
    inputData(a, b, h, n);

    if (n > 2 && a < b && h > 0) 
    {
        for (double x = a; x <= b; x += h) 
        {
            double y = function(x, n);
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

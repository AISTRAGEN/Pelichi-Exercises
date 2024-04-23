#include "header.h"

int n;

void inputData(int&a,int& b, int& h)
{
 std::cout << "Введіть значення a(min):" << std::endl;
 std::cin >> a;
 std::cout << "Введіть значення b(max):" << std::endl;
 std::cin >> b;
 std::cout << "Введіть значення n:" << std::endl;
 std::cin >> n;
 std::cout << "Введіть значення h(крок)" << std::endl;
 std::cin >> h;
}

double function(double x)
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
    int a, b, h;
    inputData(a, b, h);
   outputData(a, b, h, function);
   
   return 0;
}

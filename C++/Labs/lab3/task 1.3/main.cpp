#include <iostream>

int main() 
{
    double x, y = 1;
    int n, j = 1;
    std::cout << "Input value x: ";
    std::cin >> x;
    std::cout << "Input value n: ";
    std::cin >> n;
    if (n < 1) 
    {
        std::cout << "n must be > 1\n";
    }
    else
    {
       for (int i = 1; i <= n; ++i)
        {
            y *= x + i * j;
            j = -j;
        }
        std::cout << "Solution " << y << std::endl;
   }
    return 0;
}

#include <iostream>

int main() 
{
    double x, n, k;
    std::cout << "Input x" << std::endl;
    std::cin >> x;
    std::cout << "Input n" <<std:: endl;
    std::cin >> n;
    std::cout << "Input k" << std::endl;
    std::cin >> k;
    double y = 0;
    if (n < 1) 
    {
       std:: cout << "n must be > 1" << std::endl;
        return 0;
    }
    else 
    {
        for (int i = 1; i <= n; i++) 
        {
            if (i == k) 
            {
                continue;
            }
            else 
            {
                double b = x + (2 * i);
                if (b != 0) 
                {
                    y = y + (i / b);
                     
                }
                else
                {
                    std::cout << "Dividing by 0 is unreal";
                }
            }

        }
        std::cout << "Y value its:" << y << std::endl; 
    }
    return 0;
}


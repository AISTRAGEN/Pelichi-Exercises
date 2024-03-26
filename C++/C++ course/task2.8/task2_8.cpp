#include <iostream>

int main()
{
    int number, sum = 0;
    while(true)
    {
        std::cout << "Enter the number" << std::endl;
        std::cin >> number;
        if (number >= 0)
        {
         sum += number;
        }
        else
        {
         break;
        }
        std::cout << "Sum is:" << sum << std::endl;
    }

    return 0;
}

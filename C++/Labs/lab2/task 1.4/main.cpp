#include <iostream>

int main()
{
    int n;
    std::cout << "Input value n ( 33 to 255): ";
    std::cin >> n;
    n >= 33 && n <= 255 ? std::cout << "Value 8 = " << (1 << 3 * n) << std::endl : std::cout << "Invalid value n" << std::endl;

    return 0;
}

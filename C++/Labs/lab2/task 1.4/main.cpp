#include <iostream>

int main()
{
    int n;
    std::cout << "Input value n ( 0 to 10): ";
    std::cin >> n;
    n >= 0 && n <= 10 ? std::cout << "Value 8 = " << (1 << 3 * n) << std::endl : std::cout << "Invalid value n" << std::endl;

    return 0;
}

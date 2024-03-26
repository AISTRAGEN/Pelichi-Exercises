
#include <iostream>

int main()
{
    double y;
    double k;
    std::cout << "Input value k please" << std::endl;
   std::cin >> k;
    (k > 0) ? "Okay" : "Wrong data";
    y = (1 / k) + (1 / (k * k)) + (1 / (k * k * k));
    std::cout << y;

    return 0;
}

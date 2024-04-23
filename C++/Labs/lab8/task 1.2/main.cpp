#include <iostream>
#include <cmath>

struct Dot
{
    int x;
    int y;
    int z;
};

int calculateDots(Dot& first, Dot& second)
{
 int dx = second.x - first.x;
 int dy = second.y - first.y;
 int dz = second.z - first.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

int main()
{
    Dot first;
    Dot second;

   std::cout << "Ввведіть координати першої точки (x, y, z)" << std::endl;
   std::cin >> first.x >> first.y >> first.z;
   std::cout << "Ввведіть координати другої точки (x, y, z)" << std::endl;
   std::cin >> second.x >> second.y >> second.z;
    
    int distance = calculateDots(first, second);
    std::cout << "Відстань між точками: " << distance << std::endl;
   return 0;
}

#include <iostream>
#include <cmath>

class Point3D
{
private:
    double x, y, z;
public:
    
    Point3D() : x(0), y(0), z(0) {}

  
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }
    void setX(double newX) { x = newX; }
    void setY(double newY) { y = newY; }
    void setZ(double newZ) { z = newZ; }

   
    double operator-(const Point3D& other) const
    {
        double dx = x - other.x;
        double dy = y - other.y;
        double dz = z - other.z;
        return std::sqrt(dx * dx + dy * dy + dz * dz);
    }
};

int main()
{
    
    Point3D point1; 
    Point3D point2(3.0, 4.0, 5.0); 

    std::cout << "Точка 1: (" << point1.getX() << ", " << point1.getY() << ", " << point1.getZ() << ")" << std::endl;
    std::cout << "Точка 2: (" << point2.getX() << ", " << point2.getY() << ", " << point2.getZ() << ")" << std::endl;

    double distance = point1 - point2;
    std::cout << "Дистанція між точками: " << distance << std::endl;

    point1.setX(1.0);
    point1.setY(2.0);
    point1.setZ(3.0);

    distance = point1.operator-(point2);
    std::cout << "Дистанція між точками після модифікації: " << distance << std::endl;

    return 0;
}

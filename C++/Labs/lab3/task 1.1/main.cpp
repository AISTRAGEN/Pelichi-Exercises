 #include <iostream>
#include <cmath>

int main()
{
	double a, b, c;
	std::cout << "Enter value a:\n"; 
	std::cin >> a;                    
	std::cout << "Enter value b:\n";  
	std::cin >> b;                     
	std::cout << "Enter value c:\n";   
	std::cin >> c;                       
	if (a != 0) 
	{
        double  x1, x2;   
		double Discriminant = (b * b) - 4 * a * c; 
		if (Discriminant < 0)
		{
			std::cout << "No solutions" << std::endl;
		}
		
		if (Discriminant == 0)
		{
			x1 = -b / (2 * a);
			std::cout << x1 << "Root x1 = x2\n" << std::endl;
		}

        if (Discriminant > 0)
		{
            x1 = (-b + sqrt(Discriminant)) / (2 * a);
			 x2 = (-b - sqrt(Discriminant)) / (2 * a);
			std::cout << "Root x1 value:\n" << x1 << std::endl;
			std::cout << "\nRoot x2 value:" << x2 << std::endl;
		}
		

	}
	else if (a == 0)
	{
		if (b == 0)
		{
			if (c != 0)
				std::cout << "No solutions linear";
			if (c == 0)
			{
				std::cout << "Infinite solutions";
			}

		  }

		else
		{
			double x = -c / b;
			std::cout << "Linear value:\n" << x;
		}
		
	}
	return 0;
}

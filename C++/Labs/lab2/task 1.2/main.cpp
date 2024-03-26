#include <iostream>

int main()
{
	double x;
	int y;
	std::cout << "Input any x\n";
		std::cin >> x;
	y = ((x >= 0 && x <= 2) || (x > 7 && x < 11)) ? 1 : 0;
	std::cout << "Result its" << " " << y << std::endl;
	
	return 0;
}



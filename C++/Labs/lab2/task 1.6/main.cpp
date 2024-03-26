#include <iostream>

int main()
{
	double x, y;
	std::cout << "Input value x\n";
	std::cin >> x;
	double result = (x >= -1 && x <= 0) ? (x + (x * x * x)) : 0;
	double result2 = (x < -1) ? (x / (x - 1)) : 0;
	double result3 = (x > 0) ? (4 + 1 / (x * x * x) - 1 / (x * x * x * x)) : 0;
	std::cout << "result1\n " << result << "\nresult2\n" << result2 << "\nresult3\n" << result3 << std::endl;
	
	return 0;
}

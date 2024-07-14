#include <iostream>
#include <exception>

double divide(double x, double y) {
	if (y == 0)
		throw std::exception();
	return x/y;
}

int main() {
	try {
		double result = divide(1, 9);
		std::cout << result << std::endl;
	}
	catch (const std::exception& err)
	{
	std::cout << 2435 << std::endl;
	}
	return 0;
}

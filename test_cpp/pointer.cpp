#include <iostream>

int main() {
	int a = 111;
	std::cout << &a << '\n';
	int* p = &a;
	std::cout << p << '\n';
}


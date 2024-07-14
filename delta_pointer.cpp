#include <iostream>

int main() {
	int a = 111;
	int b = 555;
	std::cout << &a << ' ' << ' ' << ' ' << &b << ' ' << ' ' << ' ' << &b - &a << '\n';
}


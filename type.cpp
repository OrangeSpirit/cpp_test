#include <iostream>

int main() {
	char c = 'a';
	int x = 0;
	std::cout << c + 'b' << ' ' << c * '2' << '\n';
	x++ && ++x;
	std::cout << x << '\n';
	x = 0;
	++x && x++;
	std::cout << x << '\n';
	++x = 5;
	std::cout << x << '\n';
	int i = 11;
	int j = 22;
	int t = 55;
	t = i, i = j, j = t;
	std::cout << "i = " << i << '\n';
	std::cout << "j = " << j << '\n';
	std::cout << "t = " << t << '\n';
//	x++ = 5;
//	std::cout << x << '\n';
//
}

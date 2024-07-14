#include <iostream>

void swap(int a,int b) {
	int t = a;
	a = b;
	b = t;
}

void swap_pointer(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}
	
int main() {
	int a = 1;
	int b = 2;
	swap(a, b);
	std::cout << a << b << '\n' << '\n';
	swap_pointer(&a, &b);
	std::cout << a << b << '\n';
}


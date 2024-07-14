#include <iostream>
#include <string>

//using namespace std;

class Human {
	public:
	int age;
	int weight;
	std::string name;

	void print() {
		std::cout << name << ' ' << age << ' ' << weight << std::endl;
	}
};

int main() {
	Human firstHuman;
	firstHuman.age = 30;
	firstHuman.weight = 99;
	firstHuman.name = "Ivanov Ivan";
	
	firstHuman.print();

	Human secondHuman = {39, 101, "Chuk Gam"};
	secondHuman.print();

	Human firdHuman;
	firdHuman.print();

	return 0;
};



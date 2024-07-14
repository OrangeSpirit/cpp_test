#include <iostream>
#include <math.h>


class Point2D {
private:
	int x, y;
public:
	void set_coords(int a, int b)
		{x = a; y = b;}
	void get_coords(int& a, int& b)
		{a = x; b = y;}
	void print_point()
		{std::cout << "x=" << x << ' ' << "y=" << y << std::endl;}
	double length(Point2D pt) {
		double len = sqrt((x - pt.x) * (x - pt.x) + (y - pt.y) * (y - pt.y));
		return len;
	}
};


int main() {
	Point2D pt1, pt2;
	pt1.set_coords(1, 1);
	pt2.set_coords(25, 25);
	pt1.print_point();
	pt2.print_point();
	double len = pt1.length(pt2);
	std::cout << "len = " << len << std::endl;



return 0;
}
       

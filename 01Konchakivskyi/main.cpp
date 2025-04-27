#include "Point.h"
#include "Triangle.h"

#include <iostream>
using namespace std;

int main()
{
	Point u, v(0, 3), w(4);

	cout << "Triangle composing apices======" << endl;
	Triangle ABC(u, v, w);
	cout << "ABC " << ABC;

	Triangle a, b(2, 0, 2, 2, 0, 2), c(b);
	cout << "a " << a;

	cout << "b " << b;

	cout << "c " << c;

	c = ABC;
	cout << "new value of c " << c;

	cout << "Testing medians of ABC:" << endl;
	const Triangle::Segment& median_a = ABC.median_to_a();
	const Triangle::Segment& median_b = ABC.median_to_b();
	const Triangle::Segment& median_c = ABC.median_to_c();

	cout << "Median to A: " << median_a << endl;
	cout << "Median to B: " << median_b << endl;
	cout << "Median to C: " << median_c << endl;

	cout << "Triangles " << Triangle::epilog() << endl;
	cout << "Segments  " << Triangle::Segment::epilog() << endl;
	cout << "Points    " << Point::epilog() << endl;

	return 0;
}

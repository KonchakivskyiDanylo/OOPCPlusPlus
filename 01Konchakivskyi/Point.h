#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
using namespace std;
#include <fstream>
#undef NDEBUG

class Point
{
private:
	static ofstream out;
	static int _call;
	static int freeID;
	int myId;
	double _x;
	double _y;
public:
	Point(double x = 0, double y = 0);
	Point(const Point&);
	~Point();
	Point& operator=(const Point&);
	double& x()
	{
		return _x;
	}
	double& y() { return _y; }
	const double& x()const { return _x; }
	const double& y()const { return _y; }
	static int epilog();
};

ostream& operator<<(ostream&, const Point&);

const Point operator+ (const Point& u, const Point& v);
const Point operator- (const Point& u, const Point& v);
Point& operator+=(Point&, const Point&);
bool operator==(const Point& u, const Point& v);
bool operator!=(const Point& u, const Point& v);

#endif
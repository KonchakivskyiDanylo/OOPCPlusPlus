#include <iostream>
using namespace std;
#include <cmath>
#include "Point.h"

ofstream Point::out("Point.txt");
int Point::_call = 0;
int Point::freeID = 0;

Point::Point(double x, double y) :
	_x(x), _y(y), myId(++freeID)
{
	++_call;
#ifndef NDEBUG
	out << myId << "created:  " << *this << endl;
#endif
};

Point::Point(const Point& u) :
	_x(u._x), _y(u._y), myId(++freeID)
{
	++_call;
#ifndef NDEBUG
	out << myId << "copied  :" << *this << endl;
#endif
};

Point::~Point()
{
	++_call;
#ifndef NDEBUG
	out << myId << "removed : " << *this << endl;
#endif
};

Point& Point::operator=(const Point& u)
{
	++_call;
	_x = u._x;
	_y = u._y;
	return *this;
}
int Point::epilog()
{
	out << "N calls " << _call << " Total amount of created Points " << freeID << endl;
	return freeID;
}

ostream& operator<<(ostream& os, const Point& u)
{
	os << '(' << u.x() << ',' << u.y() << ')';
	return os;
}

const Point operator+ (const Point& u, const Point& v)
{
	return Point(u.x() + v.x(), u.y() + v.y());
}


const Point operator- (const Point& u, const Point& v)
{
	Point res(u);
	return res += v;
}

Point& operator+=(Point& u, const Point& v)
{
	u.x() += v.x();
	u.y() += v.y();
	return u;
}

bool operator==(const Point& u, const Point& v)
{
	return (u.x() == v.x()) && (u.y() == v.y());
}

bool operator!=(const Point& u, const Point& v)
{
	return !(u == v);
}



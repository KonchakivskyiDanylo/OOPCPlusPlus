#include "Triangle.h"
#include "Point.h"
#include <cassert>
#include <cmath>

int Triangle::_call = 0;
ofstream Triangle::out("Triangle.txt");
int Triangle::Segment::_call = 0;
ofstream Triangle::Segment::out("Segment.txt");
int Triangle::Segment::freeID = 0;

Triangle::Segment::Segment(const Point& a, const Point& b) :
	_a(a), _b(b), myId(++freeID)
{
	++_call;
#ifndef NDEBUG
	out << myId << ": a Segment was created: " << *this;
#endif
};

Triangle::Segment::Segment(const Segment& s) : _a(s._a), _b(s._b), myId(++freeID)
{
	++_call;
#ifndef NDEBUG
	out << myId << ": a Segment was copied: " << *this;
#endif
}

Triangle::Segment::~Segment()
{
	++_call;
#ifndef NDEBUG
	out << myId << ": a Segment was deleted: " << *this;
#endif
}

Triangle::Segment& Triangle::Segment::operator=(const Segment& s)
{
	++_call;
	return *this;
}

double Triangle::Segment::length() const
{
	++_call;
	return sqrt((_a.x() - _b.x()) * (_a.x() - _b.x()) + (_a.y() - _b.y()) * (_a.y() - _b.y()));
}

const Point& Triangle::Segment::start() const
{
	++_call;
	return _a;
}
const Point& Triangle::Segment::end() const
{
	++_call;
	return _b;
}

double Triangle::Segment::distance(const Point& c) const
{
	++_call;
	return 0;
}

int Triangle::Segment::epilog()
{
	out << "N calls " << _call << " Total amount of created Segments " << freeID << endl;
	return freeID;
}




Triangle::Triangle(const double x1, const double y1,
	const double x2, const double y2,
	const double x3, const double y3) :
	_a(x1, y1), _b(x2, y2), _c(x3, y3)

{
	++_call;
	assert(area() != 0);
	return;
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) :
	_a(a), _b(b), _c(c)
{
	++_call;
	assert(area() > 0);
	return;
}

Triangle::Triangle(const Triangle& t) :
	_a(t._a), _b(t._b), _c(t._c)
{
	++_call;
	return;
};
Triangle::~Triangle()
{
	++_call;
	delete _ab;
	delete _bc;
	delete _ac;

	delete _m_ab;
	delete _m_ac;
	delete _m_bc;

	delete _median_a;
	delete _median_b;
	delete _median_c;
	return;
};
Triangle& Triangle::operator= (const Triangle& t)
{
	++_call;
	if (this != &t) {
		_a = t._a;
		_b = t._b;
		_c = t._c;
		delete _ab;
		delete _bc;
		delete _ac;

		delete _m_bc;
		delete _m_ac;
		delete _m_ab;

		delete _median_a;
		delete _median_b;
		delete _median_c;

		_ab = _bc = _ac = nullptr;
		_m_bc = _m_ac = _m_ab = nullptr;
		_median_a = _median_b = _median_c = nullptr;
	}
	return *this;
}

double Triangle::perimeter() const
{
	++_call;
	return side_a().length() + side_b().length() + side_c().length();
}


double Triangle::area() const
{
	++_call;
	double a = side_a().length();
	double b = side_b().length();
	double c = side_c().length();
	double p = (a + b + c) * 0.5;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

const Point& Triangle::apexA() const
{
	++_call;
	return _a;
}
const Point& Triangle::apexB() const
{
	++_call;
	return _b;
}
const Point& Triangle::apexC() const
{
	++_call;
	return _c;
}

const Triangle::Segment& Triangle::side_a() const
{
	++_call;
	if (!_bc) {
		_bc = new Segment(_b, _c);
	}
	return *_bc;
}

const Triangle::Segment& Triangle::side_b() const
{
	++_call;
	if (!_ac) {
		_ac = new Segment(_c, _a);
	}
	return *_ac;
}

const Triangle::Segment& Triangle::side_c() const
{
	++_call;
	if (!_ab) {
		_ab = new Segment(_a, _b);
	}
	return *_ab;
}

Point* Triangle::midPoint(const Point& a, const Point& b) const
{
	return new Point((a.x() + b.x()) / 2.0, (a.y() + b.y()) / 2.0);
}


const Triangle::Segment& Triangle::median_to_a() const
{
	++_call;
	if (!_median_a) {
		if (!_m_bc) {
			_m_bc = midPoint(_b, _c);
		}
		_median_a = new Segment(_a, *_m_bc);
	}
	return *_median_a;
}

const Triangle::Segment& Triangle::median_to_b() const
{
	++_call;
	if (!_median_b) {
		if (!_m_ac) {
			_m_ac = midPoint(_a, _c);
		}
		_median_b = new Segment(_b, *_m_ac);
	}
	return *_median_b;
}

const Triangle::Segment& Triangle::median_to_c() const
{
	++_call;
	if (!_median_c) {
		if (!_m_ab) {
			_m_ab = midPoint(_a, _b);
		}
		_median_c = new Segment(_c, *_m_ab);
	}
	return *_median_c;
}


ostream& Triangle::show(ostream& os) const
{
	os << "Triangle: " << apexA() << apexB() << apexC() << endl;
	os << side_a();
	os << side_b();
	os << side_c();
	os << "perimeter " << perimeter() << endl;
	os << "area      " << area() << endl << endl;

	if (_median_a) {
		os << "Median to A: ";
		operator<<(os, *_median_a);
	}
	if (_median_b) {
		os << "Median to B: ";
		operator<<(os, *_median_b);
	}
	if (_median_c) {
		os << "Median to C: ";
		operator<<(os, *_median_c);
	}
	return os;
}



int Triangle::epilog()
{
	out << "N calls " << _call << endl;
	return _call;
}

ostream& operator<<(ostream& os, const Triangle& t)
{
	return t.show(os);
}

ostream& operator<<(ostream& os, const Triangle::Segment& u)
{
	os << u.getID() << '[' << u.start() << ',' << u.end() << ']' << endl;
	return os;
}
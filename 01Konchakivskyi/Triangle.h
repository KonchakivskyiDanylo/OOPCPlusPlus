#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Point.h"
#include <iostream>
#include <fstream>
using namespace std;

// Version 0.1
// To be developed to a version 1.0
// of the well balanced triangle
// with atributes Segment*
// for sides and medians
class Triangle
{
public:
	class Segment
	{
	private:
		static int _call;
		static ofstream out;
		static int freeID;
		int myId;
		const Point& _a;
		const Point& _b;

	public:
		Segment(const Point& a, const Point& b);
		Segment(const Segment& s);
		~Segment();
		Segment& operator=(const Segment& s);

		const Point& start() const;
		const Point& end() const;
		double length() const;
		double distance(const Point&) const;
		const int getID() const { return myId; }
		static int epilog();
	};

private:
	static ofstream out;
	static int _call;
	Point _a, _b, _c;

public:
	mutable Segment* _ab = nullptr;
	mutable Segment* _bc = nullptr;
	mutable Segment* _ac = nullptr;

	mutable Point* _m_ab = nullptr;
	mutable Point* _m_bc = nullptr;
	mutable Point* _m_ac = nullptr;

	mutable Segment* _median_a = nullptr;
	mutable Segment* _median_b = nullptr;
	mutable Segment* _median_c = nullptr;

	// possible without mutable?

	Triangle(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 0,
		const double x3 = 0, const double y3 = 1);
	Triangle(const Point& a, const Point& b, const Point& c);
	Triangle(const Triangle&);
	~Triangle();
	Triangle& operator= (const Triangle&);
	double perimeter() const;
	double area() const;

	const Point& apexA() const;
	const Point& apexB() const;
	const Point& apexC() const;

	const Segment& side_a() const;
	const Segment& side_b() const;
	const Segment& side_c() const;

	Point* midPoint(const Point& a, const Point& b) const;

	const Segment& median_to_a() const;
	const Segment& median_to_b() const;
	const Segment& median_to_c() const;


	static int epilog();

	ostream& show(ostream& os) const;
};

ostream& operator<<(ostream&, const Triangle&);
ostream& operator<<(ostream&, const Triangle::Segment&);
#endif

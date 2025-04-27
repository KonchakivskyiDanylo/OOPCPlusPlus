#include <iostream>
#include <string>
#include "Sequence.h"
#include "Point.h"

void testIntSequence() {
	std::cout << "\n=== INT SEQUENCE ===\n";

	std::cout << "\n=== 1 ===\n";
	Sequence<int> intSeq;
	intSeq.print();

	std::cout << "\n=== 2 ===\n";
	intSeq.append(10);
	intSeq.append(20);
	intSeq.append(30);
	intSeq.append(40);
	intSeq.append(50);
	intSeq.print();

	std::cout << "\n=== 3 ===\n";
	intSeq.append(60);
	intSeq.append(70);
	intSeq.print();

	std::cout << "\n=== 4 ===\n";
	int checkValue = 30;
	std::cout << checkValue << " exists in the sequence? "
		<< (intSeq.contains(checkValue) ? "yes" : "no") << std::endl;

	checkValue = 100;
	std::cout << checkValue << " exists in the sequence? "
		<< (intSeq.contains(checkValue) ? "yes" : "no") << std::endl;

	std::cout << "\n=== 5 ===\n";
	int removeValue = 30;
	std::cout << "Removing " << removeValue << " from the sequence: "
		<< (intSeq.remove(removeValue) ? "successful" : "element not found") << std::endl;
	intSeq.print();

	removeValue = 100;
	std::cout << "Removing " << removeValue << " from the sequence: "
		<< (intSeq.remove(removeValue) ? "successful" : "element not found") << std::endl;
	intSeq.print();
}

void testPointSequence() {
	std::cout << "\n=== POINT SEQUENCE ===\n";

	std::cout << "\n=== 1 ===\n";
	Sequence<Point> pointSeq;
	pointSeq.print();

	std::cout << "\n=== 2 ===\n";
	pointSeq.append(Point(1, 2));
	pointSeq.append(Point(3, 4));
	pointSeq.append(Point(5, 6));
	pointSeq.append(Point(7, 8));
	pointSeq.print();

	std::cout << "\n=== 3 ===\n";
	pointSeq.append(Point(9, 10));
	pointSeq.append(Point(11, 12));
	pointSeq.print();

	std::cout << "\n=== 4 ===\n";
	Point checkPoint(5, 6);
	std::cout << checkPoint << " exists in the sequence? "
		<< (pointSeq.contains(checkPoint) ? "yes" : "no") << std::endl;

	checkPoint = Point(5, 7);
	std::cout << checkPoint << " exists in the sequence? "
		<< (pointSeq.contains(checkPoint) ? "yes" : "no") << std::endl;

	std::cout << "\n=== 5 ===\n";
	Point removePoint(3, 4);
	std::cout << "Removing " << removePoint << " from the sequence: "
		<< (pointSeq.remove(removePoint) ? "successful" : "element not found") << std::endl;
	pointSeq.print();

	removePoint = Point(100, 200);
	std::cout << "Removing " << removePoint << " from the sequence: "
		<< (pointSeq.remove(removePoint) ? "successful" : "element not found") << std::endl;
	pointSeq.print();


	std::cout << "\n=== 6 ===\n";
	Point p1(1, 1);
	Point p2(2, 2);

	Point sum = p1 + p2;
	std::cout << "Sum of points: " << sum << std::endl;

	pointSeq.append(sum);

	pointSeq.print();
}

int main() {
	testIntSequence();

	testPointSequence(); // Used points from 1 lab

	return 0;
}
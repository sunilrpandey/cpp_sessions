#pragma once
#include <iostream>

struct Point
{
	double x, y, z;
};

void showPoint(const Point& pt) {
	std::cout << "\nPoint : [" << pt.x << "," << pt.y << "," << pt.z << "]" << std::endl;
}

int demoDesignatedInitializers()
{
	Point pt{ 2,3,4 };
	showPoint(pt);

	Point pt1{.x=5,.y=3.8,.z=9.8};
	showPoint(pt1);

	// y is missign will init to 0
	Point pt2{ .x = 5,.z = 9.8 };
	showPoint(pt2);

	// x is missing will init to zero
	Point pt3{ .y = 3.8,.z = 9.8 };
	showPoint(pt3);
	
	// missed one getting initialized with zero
	Point pt4{ .x = 3.8};
	showPoint(pt4);



	// error: since order changed
	//Point pt5{ .z = 3.8,.x = 9.8 };
	//showPoint(pt5);



	return 0;
}
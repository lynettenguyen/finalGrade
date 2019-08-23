#ifndef POINT_HPP
#define POINT_HPP
#include <utility>

class Point
{
public:
	//constructor
	Point(double current, double total, double possible);

	std::pair <bool, double> pointsNeeded(double want);

private:
	double currentPoints;
	double totalPoints;
	double possiblePoints;
};


#endif 

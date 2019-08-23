#include "point.hpp"

Point::Point(double current, double total, double possible)
{
	currentPoints = current;
	totalPoints = total;
	possiblePoints = possible;
}

std::pair<bool, double> Point::pointsNeeded(double want)
{
	double available = totalPoints - possiblePoints;               //allows us to find the available left that a student can earn
	double totalNeed = (totalPoints * want) - currentPoints;       //the minimum amount of points the student needs to reach desire goal
	std::pair <bool, double> result;
	if (totalNeed > available)									   //If there are not any enough points, returns an order pair with a bool 
	{															   //and the highest percentage the student can receive based on the point
		double maxPoints = (available+currentPoints) / totalPoints;      //balance.
		result.first = false;									   //Else, the pair returns true and the minimum amount needed to reach the 
		result.second = maxPoints;								   //their desired grade 
		return result;
	}

	else
	{
		result.first = true;
		result.second = totalNeed;
		return result;
	}
}

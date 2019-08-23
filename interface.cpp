#include "interface.hpp"


void openMessage()
{
	std::cout << "-----------------------------------------------------"   << std::endl;
	std::cout << "       Welcome to the Final Grade Calculator!" << std::endl;
	std::cout << "-----------------------------------------------------"   << std::endl;
	std::cout << "   A tool that is used to help students determine"   << std::endl;
	std::cout << "   what they need to score on their last few "  << std::endl;
	std::cout << "   assignments and/or on to get a certain grade!"<< std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
	std::cout << " " << std::endl;
}

std::string modeSelector()
{	std::string mode; 
	std::cout << "Is your class on a weighted or point system? (weight or point) " << std::endl;
	std::cin >> mode;

	if (mode != "weight" && mode != "point")
	{
        std::cout << "Choice is invalid. Please answer with weight or point." << std::endl;
		mode = modeSelector();
	}
    return mode;
}

Point createPointClass()
{
	double current, total, possible;
	std::cout << "How many points do you currently have in the class?" << std::endl;
	std::cin >> current;
	std::cout << "What is the total amount of points you can receive in this class?" << std::endl;
	std::cin >> total;
	std::cout << "How many points have been awarded already?" << std::endl;
	std::cin >> possible;

	Point currentPoint = Point(current, total, possible);

	return currentPoint;

}


void pointResult(std::pair<bool, double> result, double want)
{
	if (result.first)
	{
	    printf("You will need at least %2.2f points to achieve your goal of getting %2.2f%s \n", result.second, want*100, "%");
		//std::cout << "You will need at least " << result.second << " points to achieve your goal of getting "<< want*100 < "!" << std::endl;
	}

	else
	{
	    printf("Unfortunately, your goal of %2.2f%s cannot be met. The highest grade you can receive is %2.2f%s \n",want*100, "%", result.second*100, "%");
		//std::cout << "Unfortunately, your goal cannot be met. The highest grade you can receive is " << result.second << "." << std::endl;
	}

	std::cout << "Good luck!" << std::endl;
}

void pointMath(Point currentPoint)
{
	double want;
	std::cout << "What grade do you want in this class? Please write as a percentage with out the symbol. (i.e. 83.23)" << std::endl;
	std::cin >> want;

	want = (want/100);
	std::pair result = currentPoint.pointsNeeded(want);
	pointResult(result, want);
}

#include "interface.hpp"


int main()
{
	openMessage();
	std::string mode = modeSelector();
	if (mode == "point")
	{
		Point currentPoint = createPointClass();
		pointMath(currentPoint);
	}

	return 0;
}

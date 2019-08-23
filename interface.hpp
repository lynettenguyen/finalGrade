#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <string>
#include "point.hpp"

void openMessage();
std::string modeSelector();
Point createPointClass();
void pointMath(Point currentPoint);
void pointResult(std::pair<bool, double> result);
#endif 

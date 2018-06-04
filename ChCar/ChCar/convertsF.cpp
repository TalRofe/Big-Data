#pragma once
#include "convertsF.h"

// we get the converted angle
void toEulerianAngle(double x, double y, double z, float w, double& roll){
	double sinr = +2.0 * (w * x + y * z);
	double cosr = +1.0 - 2.0 * (x * x + y * y);
	roll = atan2(sinr, cosr);
	roll = roll * 180 / M_PI;
}
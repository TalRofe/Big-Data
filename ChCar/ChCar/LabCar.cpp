#include "LabCar.h"

void openURL(string url) { //opens the url page (the commands will be sent through the url pages)
	ShellExecute(0, 0, url.c_str(), 0, 0, SW_SHOW);
}

int LabCar::side() {
	
}

double LabCar::calcDistance(double x, double y) {
	return sqrt((this->xPos - x)*(this->xPos - x) + (this->yPos - y)*(this->yPos - y));
}

void LabCar::provideCarDetails(double xPos, double yPos, double roll) {
	xPos = xPos;
	yPos = yPos;
	roll = roll;
}
void LabCar::move(int d) {
	string urlCar = URL;

	if (d == FORWARD)
		urlCar += "/fwd";

	else if (d == BACKWARD)
		urlCar += "/bwd";

	else if (d == RIGHT)
		urlCar += "/right";

	else
		urlCar += "/left";

	openURL(urlCar);
}

void LabCar::algorithm(double x_remoteCar, double y_remoteCar, double roll_remoteCar) {
	
	// The following cases are to handle the cases where the LABCAR is way too close to edges. //
	if (xPos <= xMinTh && roll < 90 && roll > -90) {
		if (yPos > y_remoteCar)
			move(LEFT);
		else
			move(RIGHT);
	}

	else if (xPos >= xMaxTh && ((roll < -90 && roll > -180) || (roll > 90 && roll < 180))) {
		if (yPos > y_remoteCar)
			move(RIGHT);
		else
			move(LEFT);
	}

	else if (yPos >= yMaxTh && roll < 0 && roll > -180) {
		if (xPos > x_remoteCar)
			move(LEFT);
		else
			move(RIGHT);
	}

	else if (yPos <= yMinTh && roll > 0 && roll < 180) {
		if (xPos > x_remoteCar)
			move(RIGHT);
		else
			move(LEFT);
	}

	//

	else {
		double a = fabs(roll_remoteCar - roll - 360);
		double b = fabs(roll_remoteCar - roll);
		double c = fabs(roll_remoteCar - roll);

		double angleBetweenCars = fmin(fmin(a, b), c);

		if (calcDistance(x_remoteCar, y_remoteCar) > distanceThreshold) {
			if (angleBetweenCars <= 30)
				move(FORWARD);
			else {

			}
		}

		else {

		}


	}

}
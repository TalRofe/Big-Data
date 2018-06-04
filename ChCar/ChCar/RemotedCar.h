#pragma once

class RemotedCar {
private:
	double xPos;
	double yPos;
	double roll;

public:
	void provideCarDetails(double xPos, double yPos, double roll);

	double getxPos(){
		return xPos;
	}

	double getyPos(){
		return yPos;
	}

	double getRoll(){
		return roll;
	}
};
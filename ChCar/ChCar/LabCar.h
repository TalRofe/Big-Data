#pragma once

#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <shellapi.h>
#include "windows.h"
#include "Consts.h"
#include "convertsF.h"
#pragma comment(lib, "shell32.lib")

void openURL(string url);
const string url[1] = { URL };
void move(int d);

using namespace std;

class LabCar {
private:
	double xPos;
	double yPos;
	double roll;

	double calcDistance(double x, double y);

public:
	void move(int d);

	void algorithm(double x_remoteCar, double y_remoteCar, double roll_remoteCar);

	void provideCarDetails(double xPos, double yPos, double roll);

	int side();

};

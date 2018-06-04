#include "LabCar.h"
#include "RemotedCar.h"
#include "PacketClient.h"
#include <thread>

using namespace std;

// Getting details from the opti-track
void getDetails(LabCar* labCar, RemotedCar* remotedCar){
	client_main(0, NULL, labCar, remotedCar); // Set data into labCar and remotedCar from the opti-track
}

int main(){
	LabCar labCar;
	RemotedCar remotedCar;

	getDetails(&labCar, &remotedCar);

	while (1){
		labCar.algorithm(remotedCar.getxPos(), remotedCar.getyPos(), remotedCar.getRoll());
		getDetails(&labCar, &remotedCar);
	}
}
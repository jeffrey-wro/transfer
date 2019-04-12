#include <stdio.h>
#include "Motor_Controller.h"
#include "Jeffrey.h"
#include "state.h"
#include "Utils.h"


void* startedState(Jeffrey* jeffrey){

	printf("startedState\n");
	fflush(stdout);

	//move 36cm to be out of the box and 10cm to maneuver
	jeffrey->moveForwardCM(36+10, 150);

	return (void *)outOfBox;
}

void* outOfBox(Jeffrey* jeffrey){

	printf("outOfBox\n");
	fflush(stdout);

	//align perpendicular with wall
	jeffrey->alignWithWall(25, 0.75);

	return (void *)stoppedState;
}

void* stoppedState(Jeffrey* jeffrey){

	printf("stoppedState\n");
	fflush(stdout);

	return (void *)stoppedState;
}


void* pickUpCube(Jeffrey* jeffrey){

	jeffrey->openHand();

	jeffrey->weightFront();

	jeffrey->moveToDistanceForward(100, 12, true);
	jeffrey->moveToDistanceForward(50, 9, true);
	jeffrey->moveToDistanceForward(25, 6.5, true);
	jeffrey->moveToDistanceForward(10, 5.9, true);
	//jeffrey->moveToDistanceForward(25, 4, true);

	//jeffrey->moveHandToBlock();

	jeffrey->moveToDistanceForward(5, 3, true);
	jeffrey->closeHand();


	jeffrey->weightBack();

	jeffrey->moveToDistanceBackward(100, 20, true);



	return (void *)goToOtherClimate;
}


void* goToOtherClimate(Jeffrey* jeffrey){

	jeffrey->rotate90dregees(2);

	return (void *)placeCube;
}


void* placeCube(Jeffrey* jeffrey){

	jeffrey->moveToDistanceForward(100, 12, true);
	jeffrey->moveToDistanceForward(50, 9, true);
	jeffrey->moveToDistanceForward(25, 6.5, true);
	jeffrey->moveToDistanceForward(10, 5.9, true);
	jeffrey->moveToDistanceForward(5, 3, true);

	jeffrey->openHand();

	jeffrey->moveToDistanceBackward(100, 20, true);

	jeffrey->weightFront();


	return (void *)pickUpCube;
}



void* test(Jeffrey* jeffrey){

	jeffrey->test();

	return (void *)stoppedState;
}
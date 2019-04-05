#include <stdio.h>
#include "Motor_Controller.h"
#include "jeffrey.h"
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

	if(false){
		return NULL; //Next state
	}

	if(false){
		return NULL; //Next state
	}

	return (void *)stoppedState;
}

void* servo(Jeffrey* jeffrey){


	jeffrey->servo();


	return (void *)stoppedState;
}


void* pickUpCube(Jeffrey* jeffrey){

	jeffrey->openHand();

	printf("Hand opened\n");
	fflush(stdout);

	jeffrey->moveToDistanceForward(100, 12);
	jeffrey->moveToDistanceForward(50, 9);
	jeffrey->moveToDistanceForward(25, 6.5);
	jeffrey->moveToDistanceForward(10, 6.1);
	//jeffrey->moveToDistanceForward(25, 4);

	printf("first pos\n");
	fflush(stdout);

	jeffrey->moveHandToBlock();

	printf("centered hand\n");
	fflush(stdout);

	jeffrey->moveToDistanceForward(5, 3);
	jeffrey->closeHand();

	printf("final pos\n");
	fflush(stdout);

	jeffrey->moveToDistanceBackward(100, 20);

	printf("moved back\n");
	fflush(stdout);

	jeffrey->moveToDistanceForward(1000, -50);

	Utils::waitFor(5);



	return (void *)goToOtherClimate;
}


void* goToOtherClimate(Jeffrey* jeffrey){



	return (void *)placeCube;
}


void* placeCube(Jeffrey* jeffrey){


	jeffrey->moveToDistanceForward(100, 3);
	jeffrey->openHand();
	jeffrey->moveToDistanceBackward(100, 5);

	return (void *)stoppedState;
}

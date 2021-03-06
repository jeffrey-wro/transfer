#include <vector>
#include <iostream>

#include <stdio.h>

#include "MyRio.h"
#include "I2C.h"
#include "Motor_Controller.h"
#include "Utils.h"

#include "opencv2/core.hpp"

#include "ImageSender.h"
#include "Ultrasonic.h"


#include "state.h"
#include "Jeffrey.h"


using namespace std;
using namespace cv;

extern NiFpga_Session myrio_session;
NiFpga_Status status;


int main(int argc, char **argv) {
	
	status = MyRio_Open();
	if (MyRio_IsNotSuccess(status)) {
		return status;
	}

	Jeffrey jeffrey;
	jeffrey.init(&myrio_session);
	
	//start state
	//pickUpCube
	StateFunc statefunc = pickUpCube;

	while (1) {


	    statefunc = (StateFunc)(*statefunc)(&jeffrey);


		//end state
	    if(statefunc == stoppedState)
	    	break;

	}


	jeffrey.reset();
	status = MyRio_Close();

	return status;
}
#ifndef JEFFREY_H_
#define JEFFREY_H_

#include "MyRio.h"
#include "Ultrasonic.h"


	#define HAND_LEFT 0
	#define HAND_CENTER 0
	#define HAND_RIGHT 0


	#define HAND_OPEN 180
	#define HAND_CLOSED 0


class Jeffrey {
private:
	Motor_Controller mc;
    Ultrasonic ultrasonic;

	/*
	 * The number of degree to turn the (4" / 31.9cm) wheel forward one centimenter
	 *  Formula used : 360/31.918581360472
	 */
	static constexpr double WHEEL_DEGREE_CM = 11.2786968;



public:
    Jeffrey();
    ~Jeffrey();
    NiFpga_Status init(NiFpga_Session* myrio_session);
    void reset();

	void moveForwardCM(int cm, int speed);
	int alignWithWall(int speed, float calib);
	int servo();

	void moveToDistanceForward(int speed, float distance);
	void moveToDistanceBackward(int speed, float distance);
	void moveHandToBlock();
	void openHand();
	void closeHand();

};

#endif
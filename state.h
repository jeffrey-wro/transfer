#ifndef BRAIN_H_
#define BRAIN_H_

#include "jeffrey.h"

typedef void* (*StateFunc)(Jeffrey* jeffrey);

void* startedState(Jeffrey* jeffrey);
void* outOfBox(Jeffrey* jeffrey);
void* stoppedState(Jeffrey* jeffrey);
void* servo(Jeffrey* jeffrey);


void* pickUpCube(Jeffrey* jeffrey);
void* goToOtherClimate(Jeffrey* jeffrey);
void* placeCube(Jeffrey* jeffrey);



#endif
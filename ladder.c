#ifndef LADDERSYS_C
#define LADDERSYS_C

//update ladder lift
void updateLadderSys (Ladder t, int motorPower){
	motor[t.bottom] = motorPower;
	return;
};

#endif

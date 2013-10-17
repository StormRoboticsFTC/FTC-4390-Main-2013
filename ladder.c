#ifndef LADDERSYS_C
#define LADDERSYS_C

//update ladder lift
void updateLadderSys (LadderSys t, int motorPower){
	motor[t.ladderMotor] = motorPower;
	return;
};

#endif

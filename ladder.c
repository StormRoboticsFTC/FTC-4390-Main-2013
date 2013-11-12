#ifndef LADDERSYS_C
#define LADDERSYS_C

//update ladder lift
void updateLadderSys (LadderSys t, int ladderMotorPower){
	motor[t.ladderMotor] = ladderMotorPower;
	return;
};

#endif

#ifndef FLAGSYS_C
#define FLAGSYS_C

//update flag spinner
void updateFlagSys (FlagSys t, int motorPower){
	motor[t.flagMotor] = motorPower;
	return;
};

#endif

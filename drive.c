#ifndef DRIVESYS_C
#define DRIVESYS_C

void updateDriveSys (DriveSys t, int leftMotorPower, int rightMotorPower){
	motor[t.backLeft] = leftMotorPower;
	motor[t.backRight] = rightMotorPower;
	return;
}

#endif

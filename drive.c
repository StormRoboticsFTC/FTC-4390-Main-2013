#ifndef DRIVESYS_C
#define DRIVESYS_C

void updateDriveSys (DriveSys t, int backLeftMotorPower, int backRightMotorPower, int frontLeftMotorPower, int frontRightMotorPower){
	motor[t.backLeft] = backLeftMotorPower;
	motor[t.backRight] = backRightMotorPower;
	motor[t.frontLeft] = frontLeftMotorPower;
	motor[t.frontRight] = frontRightMotorPower;
	return;
}

#endif

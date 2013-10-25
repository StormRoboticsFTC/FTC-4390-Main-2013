#ifndef DRIVESYS_H
#define DRIVESYS_H

typedef struct  {
	//pointers to motors in the array motor[]
	//frontLeft and frontRight should have motorEncoders mounted
	tMotor	backLeft,
		backRight,
		frontLeft,
		frontRight;
}DriveSys;

#endif

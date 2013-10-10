#ifndef DRIVESYS_H
#define DRIVESYS_H

typedef struct DriveSys {
	//pointers to motors in the array motor[]
	//frontLeft and frontRight should have motorEncoders mounted
	tMotor frontLeft,
		   frontRight,
		   backLeft,
		   backRight;
}

#endif

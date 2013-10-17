#ifndef RAKESYS_H
#define RAKESYS_H

typedef struct {
	//pointers to motors in the array motor[]
	//frontLeft and frontRight should have motorEncoders mounted
	TServoIndex rakeServo;
}RakeSys;

#endif

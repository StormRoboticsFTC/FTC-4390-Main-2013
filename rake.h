#ifndef RAKESYS_H
#define RAKESYS_H

typedef struct {
	TServoIndex rakeServo;
	TServoIndex pendulumMoverServo;
	int maxValue, minValue, maxValue2, minValue2;
}RakeSys;

#endif

#ifndef RAKESYS_H
#define RAKESYS_H

typedef struct {
	TServoIndex rakeServo;
	TServoIndex pendulumMoverServo;
	int maxValue, minValue;
	bool buttonPressed;
}RakeSys;

#endif

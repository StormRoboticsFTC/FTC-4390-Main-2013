#ifndef RAKESYS_C
#define RAKESYS_C

//update rake opening and closing
void updateRakeSys (RakeSys t, short button1, short button2){
	if(button1==1){
		servo[t.rakeServo] = t.maxValue;
	} else if(button2==1){
		servo[t.rakeServo] = t.minValue;
	}
	return;
};

#endif

#ifndef RAKESYS_C
#define RAKESYS_C

//update rake opening and closing
void updateRakeSys (RakeSys t, short button1, short button2, short button3, short button4){
	if(button1==1){
		servo[t.rakeServo] = t.maxValue;
	} else if(button2==1){
		servo[t.rakeServo] = t.minValue;
	}
	if(button3==1 && t.buttonPressed!=true){
 		servo[t.pendulumMoverServo] += 1;
		t.buttonPressed=true;
	} else if(button4==1 && t.buttonPressed!=true){
 		servo[t.pendulumMoverServo] -= 1;
		t.buttonPressed=true;
	} else {
		t.buttonPressed=false;
 	}

	return;
};

#endif

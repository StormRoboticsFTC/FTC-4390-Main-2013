#ifndef RAKESYS_C
#define RAKESYS_C

//update rake opening and closing
void updateRakeSys (RakeSys t, bool button1, bool button2){
	if(button1){
		servo[t.rakeServo]=240;
	} else if(button2){
		servo[t.rakeServo]=50;
	}
	return;
};

#endif

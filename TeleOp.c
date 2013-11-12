#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C2_1,     backLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     backRight,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     ladderMotor,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     flagMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    rakeServo,            tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C1_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#pragma config(Motor,  mtr_S1_C1_3,     bottom,     tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#define COMPETITION

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "drive.h"
#include "drive.c"
#include "ladder.h"
#include "ladder.c"
#include "flag.h"
#include "flag.c"
#include "rake.h"
#include "rake.c"

DriveSys drive;
LadderSys ladder;
FlagSys flag;
RakeSys rake;

void initializeRobot()
{
	drive.backLeft = backLeft;
	drive.backRight = backRight;
	drive.frontLeft = frontLeft;
	drive.frontRight = frontRight;

	ladder.ladderMotor = ladderMotor;

	flag.flagMotor = flagMotor;

	rake.rakeServo = rakeServo;
	rake.maxValue = 200;
	rake.minValue = 120;

	servo[rake.rakeServo] = 135;

	return;
}

task main(){

	initializeRobot();

	#ifdef COMPETITION
	waitForStart();   // wait for start of tele-op phase
	#endif

	while (true){
		getJoystickSettings(joystick);
		updateDriveSys(drive, joystick.joy1_y1 * (100.0/128.0), joystick.joy1_y2 * (100.0/128.0), joystick.joy1_y1 * (100.0/128.0), joystick.joy1_y2 * (100.0/128.0));
		updateLadderSys(ladder, joystick.joy2_y1 * (100.0/128.0));
		updateFlagSys(flag, joystick.joy2_y2 * (100.0/128.0));
		updateRakeSys(rake, joy2Btn(1), joy2Btn(3));
	}
}

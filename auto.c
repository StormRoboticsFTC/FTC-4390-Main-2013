#pragma config(Hubs,  S1, HTServo,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     IRSensor,       sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C2_1,     backLeft,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     backRight,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     ladderMotor,   tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     flagMotor,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     frontLeft,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     frontRight,    tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C1_1,    rakeServo,            tServoStandard)
#pragma config(Servo,  srvo_S1_C1_2,    pendulumMoverServo,   tServoStandard)
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
#include "drivers/hitechnic-irseeker-v2.h"

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

        rake.pendulumMoverServo = pendulumMoverServo;

		servo[rake.rakeServo] = 135;
		servo[rake.pendulumMoverServo] = 0;

        return;
}

int maxSig(int num0, int num1, int num2, int num3, int num4){
    if(num0>num1 && num0>num2 && num0>num3 && num0>num4) return num0;
    if(num1>num2 && num1>num3 && num1>num4) return num1;
    if(num2>num3 && num2>num4) return num2;
    if(num3>num4) return num3;
    return num4;
}

void driveForward(){
    updateDriveSys(drive, 100, 100, 100, 100);
    wait1Msec(1000);
}

void driveBackward(){
    updateDriveSys(drive, -100, -100, -100, -100);
    wait1Msec(1000);
}

void turnLeft(){
    updateDriveSys(drive, -100, 100, -100, 100);
    wait1Msec(2000);
}

void placeBlock(){
    //use rake?
}

void turnRight(){
    updateDriveSys(drive, 100, -100, 100, -100);
    wait1Msec(2000);
}

void driveToRamp(){
    updateDriveSys(drive, 100, 100, 100, 100);
    wait1Msec(3000);

    turnLeft();
    turnLeft();

    updateDriveSys(drive, 100, 100, 100, 100);
    wait1Msec(3000);
}

void driveToRamp2(){
	updateDriveSys(drive, -100, -100, -100, -100);
    wait1Msec(1000);

	turnRight();

    updateDriveSys(drive, 100, 100, 100, 100);
    wait1Msec(3000);

    turnLeft();

    updateDriveSys(drive, 100, 100, 100, 100);
    wait1Msec(1000);

    turnLeft();

    updateDriveSys(drive, 100, 100, 100, 100);
    wait1Msec(3000);
}

task main(){

	initializeRobot();

	#ifdef COMPETITION
	waitForStart();   // wait for start of tele-op phase
	#endif

    //Detect IR Beacon method
    /*
    bool beaconFound=false;

    if(!beaconFound) driveForward();
    	int irs[5]; //infra-red sensor strengths, maximmum signal
        HTIRS2readAllACStrength(IRSensor, irs[0], irs[1], irs[2], irs[3], irs[4]);

        if(maxSig(irs[0], irs[1], irs[2], irs[3], irs[4])==irs[0]){
            beaconFound=true;

            //Turn and place block in basket
            turnLeft();
            driveForward();
            driveBackward();
            turnRight();

            driveToRamp();
	}
    */

    //Drive forward method
    updateDriveSys(drive, 100, 100, 100, 100);
    wait1Msec(1000);

    //Drive to ramp
    driveToRamp2();
}

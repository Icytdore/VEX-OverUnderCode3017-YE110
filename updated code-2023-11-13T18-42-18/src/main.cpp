/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FLeft                motor         1               
// FRight               motor         2               
// BRight               motor         3               
// BLeft                motor         4               
// Controller1          controller                    
// Catapult             motor         5               
// Catapult2            motor         6               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <cstdio>
//using std::endl;
using std::ofstream;
std::ofstream ofs;

using namespace vex;

competition Competition;
//MotorGroups//
motor_group FullDrivetrain = motor_group(FLeft,FRight,BLeft,BRight);
motor_group LeftDrive = motor_group(BLeft,BRight);
motor_group RightDrive = motor_group(FLeft,FRight);
motor_group Catapults = motor_group(Catapult,Catapult2);

void pre_auton(void) {
  //driveTrain//
  FullDrivetrain.setStopping(coast);
  FullDrivetrain.setVelocity(70,pct);
  //left//
  LeftDrive.setStopping(coast);
  LeftDrive.setVelocity(70,pct);
  //right//
  RightDrive.setStopping(coast);
  RightDrive.setVelocity(70,pct);
  //catapult//
  Catapults.setVelocity(50,pct);
  Catapults.setStopping(brake);

  vexcodeInit();

  }


void autonomous(void) {
  //*Autonomous Code*//
  FullDrivetrain.spinFor(fwd,4,rev,false);
    wait(1,sec);
  FullDrivetrain.spinFor(reverse,4.5,rev,false);
   wait(2,sec);
  //*Pushed Starting triball to other side +1*//
   for (int count = 0; count<300; count++) {
    Catapults.spinFor(fwd,3,turns);
    wait(25,msec);
    }
  //*Launch Triball to opposing side+1*//
 
  }


void usercontrol(void) {

  while (1) {
    /*Driver*/
    int _fwd = Controller1.Axis3.position(pct); //  Percentage
    int rot = Controller1.Axis1.position(pct);
    /*Turning*/
    FLeft.spin(vex::fwd, _fwd - rot, pct);
    FRight.spin(vex::fwd, _fwd + rot, pct);
    BLeft.spin(vex::fwd, _fwd - rot, pct);
    BRight.spin(vex::fwd, _fwd + rot, pct);
    /*Buttons*/
      if (Controller1.ButtonX.pressing())
       {motor_group(Catapult2,Catapult).spin(fwd, 30, pct);
      } 
      else if (Controller1.ButtonB.pressing()) {
      motor_group(Catapult2,Catapult).spin(reverse, 30, pct);
      }
      
    wait(20, msec);
    
  }
}

int main() {
 
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  pre_auton();

  while (true) {
    wait(100, msec);
  }
}

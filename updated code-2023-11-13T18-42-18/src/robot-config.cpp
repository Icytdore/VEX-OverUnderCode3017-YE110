#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FLeft = motor(PORT1, ratio18_1, true);
motor FRight = motor(PORT2, ratio18_1, false);
motor BRight = motor(PORT3, ratio18_1, true);
motor BLeft = motor(PORT4, ratio18_1, false);
controller Controller1 = controller(primary);
motor Catapult = motor(PORT5, ratio18_1, true);
motor Catapult2 = motor(PORT6, ratio18_1, false);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}
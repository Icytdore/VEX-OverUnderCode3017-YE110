using namespace vex;

extern brain Brain;

// VEXcode devices
extern motor FLeft;
extern motor FRight;
extern motor BRight;
extern motor BLeft;
extern controller Controller1;
extern motor Catapult;
extern motor Catapult2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );
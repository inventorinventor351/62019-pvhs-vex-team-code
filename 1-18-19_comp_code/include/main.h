#ifndef _PROS_MAIN_H_ //DO NOT TOUCH
#define _PROS_MAIN_H_ //DO NOT TOUCH

#define PROS_USE_SIMPLE_NAMES //If defined, instead of using long names for enums like E_CONTROLLER_MASTER, use more convient names usch as CONTROLLER_MASTER
#define _USE_MATH_DEFINES //If defined, math constants such as pi can be used
#include "api.h" //Includes all of the functions, variables, etc. of the PROS 3 language
using namespace pros; //Instead of typing pros::Motor() all the time, if you use this namepsace you can just do Motor()

#ifdef __cplusplus //DO NOT TOUCH
//You can add C++ only headers in here
//ex: #include <iostream>
#endif //DO NOT TOUCH

//You should include more files right under here
#include "1-18-19_comp_code\include\math.h"
#include "pragma.h"

//DO NOT TOUCH BELOW STUFF, THIS MAKES THE CODE RUN
#ifdef __cplusplus
extern "C" {
#endif
void disabled(void);
void initialize(void);
void competition_initialize(void);
void autonomous(void);
void opcontrol(void);
#ifdef __cplusplus
}
#endif
//DO NOT TOUCH ABOVE STUFF, THIS MAKES THE CODE RUN

#endif //DO NOT TOUCH
#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES

#define PROS_USE_LITERALS

#include "api.h"

using namespace pros;

#ifdef __cplusplus

    #include "pragma.h"
    #include "misc.h"
    #include "./subsystems/base.h"
    #include "./subsystems/catapult.h"
    #include "./subsystems/intake.h"

#endif

#ifdef __cplusplus

    extern "C" {

#endif

        void autonomous(void);
        void initialize(void);
        void disabled(void);
        void competition_initialize(void);
        void opcontrol(void);

#ifdef __cplusplus

    }

#endif

#endif

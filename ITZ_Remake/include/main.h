#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

#define PROS_USE_SIMPLE_NAMES

#ifdef __cplusplus

#endif

#include "api.h"

using namespace pros;

extern int autonCount;

#include "pragma.h"
#include "misc.h"
#include "./subsystems/base.h"
#include "./subsystems/lift.h"

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
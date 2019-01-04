#include "main.h"

void autonomous() 
{
    bool transmissionVar = 0, liftVar = 0, tipperVar = 0, atckR2, atckY, atckA, atckUp = 1, finished = 1;
	vision_signature_s_t REDCAP;
    REDCAP.id = 1;
    REDCAP.range = 2.8;
    REDCAP.u_min = -3383;
    REDCAP.u_max = -2431;
    REDCAP.u_mean = -2907;
    REDCAP.v_min = -4711;
    REDCAP.u_max = -2891;
    REDCAP.v_mean = -3801;
    REDCAP.type = 0;
    visn.set_signature(1, &REDCAP);

	bool transmissionVar = 0, liftVar = 0, tipperVar = 0, atckR2, atckY, atckA, atckUp = 1, finished = 1;
	vision_signature_s_t BLUECAP;
    BLUECAP.id = 1;
    BLUECAP.range = 2.8;
    BLUECAP.u_min = -3383;
    BLUECAP.u_max = -2431;
    BLUECAP.u_mean = -2907;
    BLUECAP.v_min = -4711;
    BLUECAP.u_max = -2891;
    BLUECAP.v_mean = -3801;
    BLUECAP.type = 0;
    visn.set_signature(1, &BLUECAP);

}

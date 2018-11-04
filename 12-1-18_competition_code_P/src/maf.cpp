#include "main.h"


float Pi = 3.1415926535897932384;

float rotToIn(float Rotations) 
{
    return (Rotations * 4.125 * Pi);
}

float inToRot(float Inches)
{
    return (Inches / 4.125 / Pi);
}
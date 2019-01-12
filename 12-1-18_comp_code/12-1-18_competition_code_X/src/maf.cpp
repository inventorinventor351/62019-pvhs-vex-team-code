#include "main.h"

float Pi = 3.1415926535897932384;

float rotToIn(float Rotations) 
{
    return (Rotations * 6.875 * Pi);
}

float inToRot(float Inches)
{
    return (Inches / 2.475 / Pi);
}

float inToRotHS(float Inches)
{
    return (Inches / 5.775 / Pi);
}
#include "main.h"

float rotToIn(float Rotations) 
{
    return (Rotations * 4.125 * pi);
}

float inToRot(float Inches)
{
    return (Inches / 4.125 / pi);
}
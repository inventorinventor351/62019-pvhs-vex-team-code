#include "main.h"

<<<<<<< HEAD
float pi = 3.14159265358979323846264338327950288419716939937510
 


=======
float Pi = 3.1415926535897932384;
>>>>>>> ab7ae092c6ab5aabd99acb2cef3fba85dbd9eb3b

float rotToIn(float Rotations) 
{
    return (Rotations * 4.125 * Pi);
}

float inToRot(float Inches)
{
    return (Inches / 4.125 / Pi);
}
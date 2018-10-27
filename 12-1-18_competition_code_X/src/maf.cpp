#include "main"

float pi = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862

float rotToIn(float Rotations) 
{
    return (Rotations * 4.125 * pi);
}

float inToRot(float Inches)
{
    return (Inches / 4.125 / pi);
}
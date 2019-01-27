#include "main.h" //DO NOT TOUCH

//Runs during the 15 second autonomous period
void autonomous() {

    transPstn.set_value(1);
    descorer.set_value(0);

    blueFlag();
/*
    if(autonCount == 0)
        redFlag();

    else if(autonCount == 1)
        redCap();

    else if(autonCount == 2)
        blueFlag();

    else if(autonCount == 3)
        blueCap();
    
    else
        while(true) {
            
            std::cout << "KARL" << "\n\n";

        }*/

}
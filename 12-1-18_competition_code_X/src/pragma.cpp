#include "main"

Motor leftChassis1(1, motor_gearset_18, 0, e_motor_encoder_rotation); //Port 1, 200 RPM gearset, not reversed, units of rotations for encoder
Motor leftChassis2(2, motor_gearset_18, 0, e_motor_encoder_rotation); //Port 2, 200 RPM gearset, not reversed, units of rotations for encoder
Motor rightChassis1(3, motor_gearset_18, 1, e_motor_encoder_rotation); //Port 3, 200 RPM gearset, reversed, units of rotations for encoder
Motor rightChassis2(4, motor_gearset_18, 1, e_motor_encoder_rotation); //Port 4, 200 RPM gearset, reversed, units of rotations for encoder
Motor intake(5, motor_gearset_18, 0, e_motor_encoder_rotation); //Port 5, 200 RPM gearset, not reversed, units of rotations for encoder
Motor shooter(6, motor_gearset_18, 0, e_motor_encoder_rotation); //Port 6, 200 RPM gearset, not reversed, units of rotations for encoder

Vision shooterEye(7); //Port 7, vision sensor for shooter


ADIDigitalOut intakeLift(1); //Port 1, solonoid for raising intake
ADIDigitalOut intakeLift1(2); //Port 2, solonoid for raising intake

ADIDigitalOut leftChassisTrans(3); //Port 3, solonoid for changing strenght and speed on left chassis
ADIDigitalOut rightChassisTrans(4); //Port 4, solonoid for changing strength and speed on right chassis

ADIDigital tipper(5); //Port 5, solonoid for cap tipping

ADIAnalogIn potentiometer(6); //Port 6, potentiometer for shooter
ADIAnalogIn ballSensor(7); //Port 7, light sensor for the ball
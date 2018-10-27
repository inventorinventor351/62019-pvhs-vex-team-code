#include "main"

Motor leftChassis1(1, motor_gearset_18, 0, e_motor_encoder_rotation); //Port 1, 200 RPM gearset, not reversed, units of rotations for encoder
Motor leftChassis2(2, motor_gearset_18, 0, e_motor_encoder_rotation); //Port 2, 200 RPM gearset, not reversed, units of rotations for encoder
Motor rightChassis1(4, motor_gearset_18, 1, e_motor_encoder_rotation); //Port 4, 200 RPM gearset, reversed, units of rotations for encoder
Motor rightChassis2(5, motor_gearset_18, 1, e_motor_encoder_rotation); //Port 5, 200 RPM gearset, reversed, units of rotations for encoder
Motor intake(7, motor_gearset_18, 0, e_motor_encoder_rotation); //Port 7, 200 RPM gearset, not reversed, units of rotations for encoder
Motor shooter(8, motor_gearset_18, 0, e_motor_encoder_rotation); //Port 8, 200 RPM gearset, not reversed, units of rotations for encoder

Vision shooterEye();

ADIAnalogIn potentiometer(1); //Port 1, potentiometer for shooter
ADIAnalogIn ballSensor(3); //Port 3, senses when the ball passes into the shooter

ADIDigitalOut intakeLift();
ADIDigitalOut intakeLift1();

ADIDigitalOut leftChassisTrans();
ADIDigitalOut rightChassisTrans();

ADIDigital tipper();
Title: Lab Report on Ultrasonic Radar System With RGB Indicator, Sound Warning and Servo Motor

Objective:
The main aim of the lab was to design and develop an Arduino-based Ultrasonic Radar System, which uses an ultrasonic sensor for detection of objects, a servo motor for sensor rotation, an RGB LED for visual warning, and a buzzer for auditory warning. The system also provides a user-friendly interface through an LCD screen and a toggle switch to control the operation of the radar.

Materials and Methods:
The lab required the following materials:

Arduino UNO
HC-SR04 Ultrasonic Sensor
Servo Motor
RGB LED
Buzzer
LCD Display (16x2)
Potentiometer
Toggle switch
Respective Libraries (<LiquidCrystal_I2C.h>, <Servo.h>, <Wire.h>, and <NewPing.h>)
The main function run_radar() is called inside the loop(). When the system is on, this function continuously monitors the surrounding area by rotating the ultrasonic sensor using a servo motor and checking for objects within a user-defined range. This range can be adjusted using the potentiometer attached to the analog input SWITCH_PIN.

When the radar detects an object within the specified range, the function warning_blink() is activated. This function alternates the color of the RGB LED between red and blue while simultaneously controlling the buzzer to alert the user of the detected object.

The function sonar_detect() calculates the distance to an object based on the time it takes for an ultrasonic ping to return to the sensor. If an object is detected within the set range, a warning is displayed on the LCD screen.

Results:
The radar system functioned as intended. It was able to detect objects in its path accurately and promptly notify through visual and auditory warnings. The servo motor allowed for a broad field of view by enabling the radar to scan across a 180-degree arc. The user interface was interactive and user-friendly, enabling the adjustment of the detection range and displaying the current status and measurements on the LCD.

Conclusion:
This lab exercise successfully demonstrated the principles of ultrasonic sensing and object detection. It also provided practical experience in interfacing various components with Arduino, including an ultrasonic sensor, RGB LED, buzzer, LCD display, and a servo motor. The project could be further enhanced by incorporating features like object tracking or mapping the detected objects in a visual format on a computer screen.

Future Work:
Improvements can be made by adding more sensors for a full 360-degree coverage or incorporating a communication module to send alert notifications to a remote device. The use of an advanced ultrasonic sensor can also enhance the precision and reliability of the system.
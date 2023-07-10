### Design and Implementation of an Ultrasonic Radar System With RGB Indicator, Sound Warning and Servo Motor

##### Introduction:

- Problem Definition:
> Object detection systems have extensive applications in robotics, automation, security, and vehicle navigation. The goal of this project is to develop an interactive and user-friendly object detection system that provides both visual and auditory alerts when an object is detected.
Solution: Our solution is an Arduino-based Ultrasonic Radar System, which uses an ultrasonic sensor for object detection, a servo motor for sensor rotation, an RGB LED for visual warnings, a buzzer for auditory warnings, and an LCD display to show system status and detected object distances.
- Body:
> 1. Hardware Description: Our hardware components consist of an Arduino UNO, an Ultrasonic Sensor, a Servo Motor, an RGB LED, a Buzzer, a 16x2 LCD Display, a Potentiometer, and a Toggle switch. Each of these components plays a crucial role in the overall functionality of the system.
> 2. Hardware Diagram: 
  > ![SonarRadarSecuritySys](https://github.com/MC-CIS-033-53082-2023/ultrasonic-radar/assets/39641108/b2ed19a7-6077-460f-83ee-86a3d0a719c4)
> 4. Software Flow: Our Arduino code initializes the hardware components and continuously monitors for the presence of objects within a user-specified range. If an object is detected within this range, the system activates the RGB LED and the buzzer to provide alerts.
  >  ![Software Flow](https://github.com/MC-CIS-033-53082-2023/ultrasonic-radar/assets/39641108/24115ca3-6ec9-43a6-acc2-7a4428c17caf)
> 6. Code Explanation: Our Arduino code uses several key functions to implement the required features of the system. For instance, the run_radar() function is the main function which controls the radar operation. Other functions like warning_blink() and sonar_detect() manage the alert system and object distance detection, respectively.

- Results:

> 1. We successfully tested the system for various objects at different distances and found that it was able to accurately detect objects and generate appropriate alerts.

- Conclusion:

> 1. Learning: Throughout the project, we developed a comprehensive understanding of Arduino programming, interfacing multiple hardware components, and implementing object detection using an ultrasonic sensor. This project also honed our problem-solving and teamwork skills.
> 2. Future Work: In the future, this project can be extended by integrating a Wi-Fi module to send alert notifications to a mobile device, enhancing the field of view with additional sensors, or incorporating object tracking functionality.

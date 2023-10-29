# Car Control
## Table of Contents
- [Intro](#intro)
- [Gamepad](#gamepad)

## Intro 
This document describes how to control the car. <br>

## Gamepad - User Interface

<img src="./images/gamepad.png" >|

| Button | Action |
| ------ | ------ |
| Left Joystick | Steering |
| Right Joystick | Throttle |
| L1 | Left Turn Signal |
| R1 | Right Turn Signal |
| X | Neutral ("N")|
| A | Drive ("D")|
| B | Park ("P")|
| Y | Reverse ("R")|

The car's steering and throttle are controlled by the joysticks. <br>
The car's turn signals are controlled by the L1 (left indicator) and R1 buttons (right indicator). <br>
The car's gear is selected by the X (Neutral), A (Drive), B (Park), and Y (Reverse) buttons. <br>
If the car is in Drive ("D"), the car will drive forward. <br>
If the car is in Reverse ("R"), the car will drive backwards. <br>
In "D" the Joystick needs to be pushed forward to drive forward. Hence, the car will not move if the Joystick is pushed backwards. <br>
The same rule apply for the gear selection reverse ("R") just in reverse. <br>
Last but not least, in Park ("P") & Neutral mode ("N"), the car will not move. <br>

## Car Control - Software Interface
Class Car has these attributes that hold the follwoing values: <br>

Attribute | Value
--- | ---
throttle | -1.00 (reverse) up to +1.00 (forward) 
max_throttle | 0.00 up to 1.00 
steering | -1.00 (left) up to +1.00 (right) 
max_steering | 0.00 up to 1.00 
indicator | "L" (left), "R" (right), None (no indicator)
gear | "P" (park), "N" (neutral), "D" (drive), "R" (reverse) (default: "N")

Note: steering & throttle are multiplied by max_throttle and max_steering to limit the max values. max_throttel default: 0.3 & max_steering default: 1.00<br>



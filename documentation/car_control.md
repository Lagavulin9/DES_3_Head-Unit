# Car Control
</br>

# Index
## [Introduction](#introduction-1)
</br>

# How to use
## Github Actions
Use github workflows to generate srg-gen code from fidl files. 
## Build Applications 
Run build.sh to build. 
```bash
./scripts/Build.sh
```
## Run Application (Sercive & Client)
Run to start vSOME/IP service
```bash
./scripts/Run_Services.sh
```
Slit Terminal. 
```bash
./scripts/Run_Client.sh
```
## Embedded Python in C++

The Application "car_control" uses embedded python. Read the follwing docs if you want to know more about it. 

- Python / C API
http://books.gigatux.nl/mirror/pythonprogramming/0596000855_python2-CHP-20-SECT-5.html
https://docs.python.org/3/c-api/index.html 
https://docs.python.org/3/c-api/import.html
https://github.com/SEA-ME-COSS/DES-Head-Unit/blob/%2311_piracer_client/piracer_sender_operator/src/PiracerOperator/PiracerClass.hpp
https://docs.python.org/3/library/sys_path_init.html

# Car Control
## Table of Contents
- [Intro](#intro)
- [Gamepad](#gamepad)

## Intro 
This document describes the functionality of the application car control. <br>

## Gamepad

The car's drivetrain is controlled by Gamepad and Head Unit inputs. <br>
Steering and acceleration are set with the joysticks. <br>
Changing lanes can be indicated by a button push of L1 (left indicator) or R1 (right indicator). <br>
The car's gear is selected by the X (Neutral), A (Drive), B (Park), and Y (Reverse) buttons. <br>
If the car is in Drive ("D"), the car will drive forward - In Reverse ("R"), the car will drive backwards. 
The right joystick needs to be pushed in the corresponding direction to accelerate. Hence, the car will not move if the Joystick is pushed backwards while "D is selected. The same rule apply for the gear selection reverse ("R") just in reverse. Last but not least, in Park ("P") & Neutral ("N"), the car will not move at all. <br>

<img src="./images/gamepad.png" width=50%>|

| Button | Action |
| ------ | ------ |
| Left Joystick | Steering |
| Right Joystick | Throttle |
| L1 | Left Indicator|
| R1 | Right Indicator |
| X | Neutral ("N")|
| A | Drive ("D")|
| B | Park ("P")|
| Y | Reverse ("R")|

## Common API - vSOME/IP

!! NEEDS TO BE EDITED !! <br>

The communication between the Head Unit and the Car Control is based on the vSOME/IP protocol. <br>

The application "Head_Unit" (in the following titled as "Head Unit") acts as a client and application "Car_Control" (titled as "Car Control") runs as a services. <br>

The vSOME/IP interface of the application car control is definfied in the .fidl file. <br>
The interface contains two attributes "indicator" and "gear" as well as a method called "gearSelectionHeadUnit". <br>
A client can subscribe to the attributes to get notified about changes. <br>
By invoking the method "gearSelectionHeadUnit", the client (in this case Head Unit) can request the car's gear via synchronous call. <br>

```ruby
package commonapi

interface CarControl {
    version { major 0 minor 1 }

    attribute String indicator readonly
    attribute String gear readonly
    
    method gearSelectionHeadUnit {
        in { 
            String selectedGear
        }
        out { 
            Boolean accepted
        }
    }
}
```

The Head Unit can invoke the method "gearSelectionHeadUnit" on the service side to set the gear. <br>
In the Request-Resonse communication, the Head Unit will sends a request with the selected gear ("D", "R", "P", "N") to the service. The service will response with "true" if the gear change was accepted.<br>
```cpp
 --------------------------- 
Result of synchronous call: 
   callStatus: SUCCESS
   Input Gear:  R
   Output Gear Change accepted: 1
 ---------------------------
```
The service receives the request and checks if the car is in motion. If the car is not in motion, the car will accept the gear change. 
```cpp
 ---------------------------
Head Unit invoked service method & tries to set gear.
  Input Gear: R
->Gear change accepted.
 ---------------------------
 ```
Next, the service will set the attribute "Gear" to the selected gear. All clients which subscriped to this attribute will recieve a notification about the change.<br>
```cpp
 ---------------------------
Service Notification: 'Gear' changed to : R
 ---------------------------
```
A gear change request will be declined, if the car is still in motion. Therefore, the output of the client's synchronous call will false. <br>

```cpp
 ---------------------------
Result of synchronous call: 
   callStatus: SUCCESS
   Input Gear:  D
   Output Gear Change accepted: 0
 ---------------------------
```
The same rules applies for a gear change input made by the Gamepad. <br>
```cpp
 ---------------------------
GamePad tries to set gear. 
  Input Gear: R
->Gear change declined.
 ---------------------------
```
If the shoulder button L1 is pressed, the service will notify the client about the change of the attribute "Indicator". The attribute indicator toggles between the selected direction ("Left" in case of L1) and "None" if the button is released. <br>
The same rules applies for the shoulder button R1. <br>
```cpp
 ---------------------------
Service Notification: 'Indicator' changed to : Left
 ---------------------------
  ```
```cpp
 ---------------------------
Service Notification: 'Indicator' changed to : None
 ---------------------------
  ```
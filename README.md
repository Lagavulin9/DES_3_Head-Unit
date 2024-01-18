# DES03 Project - Head Unit

!! UNDER CONSTRUCTION !! <br>

## Table of contents
  - [Introduction](#introduction)
  - [Collaborators](#collaborators)
  - [Demonstration Video](#demonstration-video)
  - [Project Structure](#project-structure)
  - [Architecture](#architecture)
  - [Documentation](#documentation)
  <!-- - [Known Issues](#known-issues) -->

## Introduction
This project is part of the [embedded software development cirriculum at SEA-ME](https://github.com/SEA-ME/DES_Head-Unit). <br>

It aims to develop a **Head Unit application** running on a Raspberry Pi (RPi as ECU) alongside the previously developed PiRacer **Instrument Cluster application**. <br> 
The Head Unit application will provide additional features like **ambient lighting, gear selection, and a media app**. <br> 
Furthermore, the project uses **Scalable Service-Oriented Middleware(vSOME/IP)** for the in-vehicle communication and **Yocto as the build system** for the ECU. <br> 

## Collaborators
If you find any kinds of bugs or issues, please contact 
[Kian](https://github.com/kianwasabi), 
[Jinghong](https://github.com/Lagavulin9) or 
[Seungwoo](https://github.com/SeungWoo-L). 👌🏽

## Demonstration Video
The following videos demonstrate the features of the project. <br>

Head-Units' Media Player : <br>
<img src="./documentation/images/media_player.gif" width="40%" margin="120%"> <br>
Ambient Lighting Control via Head-Unit: <br>
<img src="./documentation/images/gear_selection.gif" width="40%" margin="120%"> <br>
Gear Selection by Head-Unit: <br>
<img src="./documentation/images/instrument_cluster.gif" width="40%" margin="120%"> <br>
Essential Car Information on Dashboard: <br>
<img src="./documentation/images/car_info.gif" width="40%" margin="120%"> <br>
PiRacer drives around: <br>
<img src="./documentation/images/car_remote.gif" width="40%" margin="120%"> <br>
 
## Project Structure

The following image shows the project structure and roll-out workflows for the DES3 Head-Unit project. <br>
It is devided into four folders. <br>
- `apps`: contains submodules which hold the source code to run the car. <br> 
- `sensors`: contains submodules for the sensors' controllers that feed vehicle CAN bus. <br>
- `image`: contains a submodule that provides config files and recipes to bitbake the vehicles' ECU yocto image. _(Note: The bitbake recipes are fetching the apps' source code from the submodules' repositories.)_<br>
- `documentation`: summarizes all the projects' documentation. <br>

> _The development in each submodule is done individually by the assigned developer. <br>
Once a feature is ready, a new release following the teams' [conventions](/documentation/project_conventions.md) is published._ <br>

Next, the sensors' controller and the ECU needs to be flashed. <br> 

- `sensors` 
  - Clone DES_3_Head-Unit repository. <br>
  - Choose the sensors' directory from the sensors folder. <br>
  - Flash the sensors' controller using the Arduino IDE. <br>

- `image`
  - Clone DES_3_yocto repository. <br>
  - Bitbake the yocto image. <br>
  - Flash the yocto image on the ECU by loading the it on the RPis' SD-Card. <br>

<img src="./documentation/images/project_structure.png"> <br>

## Architecture
The following image gives a brief overview about the [software structure](/documentation/software_structure.md) that runs on the cars' [system structure](/documentation/system_structure.md). <br>
Each application like [head-unit](/documentation/headunit.md), [dashboard](/documentation/dashboard.md), [can_receiver](/documentation/can_receiver.md), [car_control](/documentation/car_control.md), and [car_info](/documentation/car_info.md) serves a different purpose and uses different peripheral interfaces and devices. <br> 
BMWs' [CommonAPI](/documentation/common_api.md) ensure the communication between the applications via Scalable Service-Oriented Middleware over IP (SOME/IP). It is easy to add more apps to the system by using the [CI/CD workflows for CommonAPI](/documentation/workflows.md) we build. <br>
In the current setup, the [speed sensor](/documentation/rpm_speedsensor.md) is the only sensor that feeds the cars' [CAN bus](/documentation/can_bus.md) but it can seamlessly be extended by adding more sensors to the CAN bus. <br>

<img src="./documentation/images/head_unit_structure.png" width="75%" margin="120%"> <br>

## Documentation
As mentioned above, the `documentation` folder contains all the projects' documentation. The files are distinguished by the phases the project went through. If you seek for more informations, don't hesitate to read through the following docs.  
<br>
1) Requirements Gathering: 
  - [🧑🏽‍🏫 subject](/documentation/subject.md) 
  - [📝 project requirments](/documentation/project_requirments.md)
2) Planning Design, System & Software:
  - [🧑🏽‍🎨 frontend design](/documentation/design.md)
  - [🏎 system structure](/documentation/system_structure.md)
  - [👨🏽‍💻 software structure](/documentation/software_structure.md)
3) Team Collaboration:
  - [🔓 conventions](/documentation/project_conventions.md)
  - [📋 kanban board](https://github.com/users/Lagavulin9/projects/2)
4) Integration: <br>
    - Technologies:
      - [⬅️ CAN bus](/documentation/can_bus.md)
      - [🔛 vSOME/IP & CommonAPI](/documentation/common_api.md)
      - [🤖 CI/CD workflow](/documentation/workflows.md)
      - [🍪 Yocto](/documentation/yocto.md)
    - Applications: 
      - [1️⃣ head-unit](/documentation/headunit.md)
      - [2️⃣ dashboard](/documentation/dashboard.md)
      - [3️⃣ can bus receiver](/documentation/can_receiver.md)
      - [4️⃣ car control](/documentation/car_control.md)
      - [5️⃣ car information](/documentation/car_info.md)
    - Sensors: <br>
      - [6️⃣ rpm speed sensor](/documentation/rpm_speedsensor.md)
5) Testing: 
  - [📝 test requirments](/documentation/project-requirments.md)

<!-- ## Known Issues 
Issues we found while testing. <br>
| Issue | Description |
| --- | --- | -->



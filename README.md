# DES03 Project - Head Unit

## Table of contents
  - [Introduction](#introduction)
  - [Collaborators](#collaborators)
  - [Architecture](#architecture)
  - [Demonstration Video](#demonstration-video)
  - [Documentations](#documentations)
  - [Known Issues](#known-issues)

## Introduction
This project is part of the [embedded software development cirriculum at SEA-ME](https://github.com/SEA-ME/DES_Head-Unit). <br>

This project aims to develop a **Head Unit application** running on a Raspberry Pi (RPi as ECU) alongside the previously developed PiRacer **Instrument Cluster application**. <br> 
The Head Unit application will provide additional features like **ambient lighting, gear selection, and a media app**. Furthermore, the project will use **Scalable Service-Oriented Middleware(vSOME/IP)** for the in-vehicle communication and **Yocto as the build system** for the ECU. <br> 

## Demonstration Video
The following video demonstrates the features of the project. <br>

Head-Units' Media Player : <br>
<img src="./documentation/images/media_player.gif" width="40%" margin="120%"> <br>
Ambient Lighting Control via Head-Unit: <br>
<img src="./documentation/images/gear_selection.gif" width="40%" margin="120%"> <br>
Gear Selection by Head-Unit: <br>
<img src="./documentation/images/instrument_cluster.gif" width="40%" margin="120%"> <br>
Essential Car Information on Dashboard: <br>
<img src="./documentation/images/car_info.gif" width="40%" margin="120%"> <br>
 
## Project Structure
This repository summarizes the entire "DES_03_Head-Unit" project that is devided into the following folders: <br>
- `apps`: Contains the submodules of each application running on the car. <br>
- `sensors`: Contains the submodules for all sensors that feed the CAN BUS. <br>
- `image`: Contains the submodule for the yocto image. <br>
- `documentation`: Contains all the documentation for the project. <br>

<img src="./documentation/images/project_structure.png"> <br>

## Architecture
! Insert a diagram of the architecture here. ! <br>

For a more detailed explanantion, see: [software architecture](/documentation/software_structure.md). <br>

## Documentation
- Requirements Gathering: 
  - [🧑🏽‍🏫 subject](/documentation/subject.md)
  - [📝 project requirments](/documentation/project-requirments.md)
- Planning Design, System & Software:
  - [🧑🏽‍🎨 frontend design](/documentation/design.md)
  - [🏎 system strucutre](/documentation/system-structure.md)
  - [👨🏽‍💻 software strucutre](/documentation/software_structure.md)
  - [🔓 conventions](/documentation/project_conventions.md)
  - [📋 project kanban ](https://github.com/users/Lagavulin9/projects/2)
- Integration:
  - Applications: 
    - [1️⃣ head unit](/documentation/headunit.md)
    - [2️⃣ dashboard](/documentation/dashboard.md)
    - [3️⃣ can bus receiver](/documentation/can_receiver.md)
    - [4️⃣ car control](/documentation/car_control.md)
    - [5️⃣ car information](/documentation/car_info.md)
  - Sensors: 
    - [6️⃣ rpm speed sensor](/documentation/rpm_speedsensor.md)
  - Technologies:
    - [🔛 can bus](/documentation/common_api.md)
    - [🔛 vSOME/IP & CommonAPI](/documentation/common_api.md)
    - [🤖 CI/CD workflows](/documentation/workflows.md)
    - [🍪 Yocto](/documentation/yocto.md)
- Testing: 
  - [📝 test requirments](/documentation/project-requirments.md)

## Known Issues 
Issues we found while testing. <br>
| Issue | Description |
| --- | --- |

## Collaborators
If you find any kinds of bugs or issues, please contact the contributes: <br>
[Kian](https://github.com/kianwasabi) <br>
[Jinghong](https://github.com/Lagavulin9) <br>
[Seungwoo](https://github.com/SeungWoo-L) <br>


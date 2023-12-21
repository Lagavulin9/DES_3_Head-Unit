# DES03 Project - Head Unit

## Table of contents
  - [Introduction](#introduction)
  - [Collaborators](#collaborators)
  - [Architecture](#architecture)
  - [Demonstration Video](#demonstration-video)
  - [Documentations](#documentations)
  - [Known Issues](#known-issues)

## Introduction
This project is part of the [embedded software development cirriculum at SEA-ME](https://github.com/SEA-ME/DES_Head-Unit).
> This project aims to develop a **Head Unit application** running on a Raspberry Pi (RPi as ECU) alongside the previously developed PiRacer **Instrument Cluster application**.
The Head Unit application will provide additional features like **ambient lighting, gear selection, and a media app**.
Furthermore, the project will use **Scalable Service-Oriented Middleware(vSOME/IP)** for the in-vehicle communication and **Yocto as the build system** for the ECU. <br> 

## Collaborators
If you find any kinds of bugs or issues, please contact the contributes [Kian](https://github.com/kianwasabi), [Jinghong](https://github.com/Lagavulin9) or [Seungwoo](https://github.com/SeungWoo-L). 👍  <br>

## Architecture
!! Add a diagram of the architecture here. !! <br>
!! SAME AS THE ONE IN THE DOCUMENTATION that will be in software-strucutre.md !! <br>

## Demonstration Video
!! UPLOAD A VIDEO OF THE DEMONSTRATION WITH THE FILENAME that shows a FEATURE FROM PROJECT REQ. !! <br>
<img src="./documentation/images/media_player.gif" width="40%" margin="120%">
<img src="./documentation/images/gear_selection.gif" width="40%" margin="120%">
<img src="./documentation/images/instrument_cluster.gif" width="40%" margin="120%">
<img src="./documentation/images/car_info.gif" width="40%" margin="120%">

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
Some issues we found while testing. <br>
| Issue | Description |
| --- | --- |



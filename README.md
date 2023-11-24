# DES03 Project - Head Unit

## Table of contents
  - [Introduction](#introduction)
  - [Collaborators](#collaborators)
  - [Documentations](#documentations)
  - [Architecture](#architecture)
  - [Demonstration Video](#demonstration-video)
  - [Known Issues](#known-issues)

## Introduction
This project is part of the embedded software development course at [SEA-ME](https://github.com/SEA-ME).
> This project aims to develop a **Head Unit application** running on a Raspberry Pi (RPi as ECU) alongside the previously developed PiRacer **Instrument Cluster application**. <br> 
The Head Unit application will provide additional features like **ambient lighting, gear selection, and a media app**. <br> 
Furthermore, the project will use **Scalable Service-Oriented Middleware(vSOME/IP)** for the in-vehicle communication and **Yocto as the build system** for the ECU. <br> 

You can see the full subject of this project [here](subject.md) or in SEA:ME's [DES Head-Unit repository](https://github.com/SEA-ME/DES_Head-Unit).

## Collaborators
If you find any kinds of bugs or issues, please contact us. <br>
🦭 [Kian](https://github.com/kianwasabi)       <br>
🐈 [Jinghong](https://github.com/Lagavulin9)   <br> 
🦚 [Seungwoo](https://github.com/SeungWoo-L)   <br>

## Documentations
You can see all documentations in [`/documentation/`](/documentation/) folder. 

- Planning:
  - [🧑🏽‍🎨 design.md](/documentation/design.md)
  - [📝 project-requirments.md](/documentation/project-requirments.md)
  - [🏎 system-strucutre.md](/documentation/system-strucutre.md)
  - [👨🏽‍💻 software-strucutre.md](/documentation/project-management.md)
- Built Applications:
  - [1️⃣ headunit.md](/documentation/headunit.md)
  - [2️⃣ dashboard.md](/documentation/dashboard.md)
  - [3️⃣ can_receiver.md](/documentation/can_receiver.md)
  - [4️⃣ car_control.md](/documentation/car_control.md)
  - [5️⃣ car_info.md](/documentation/car_info.md)
- Software Technologies:
  - [🔛 common_api.md](/documentation/common_api.md)
  - [🤖 workflows.md](/documentation/workflows.md)
  - [🍪 yocto.md](/documentation/yocto.md)

- Project's KANBAN board: <br>
  - [📋 kanban.md](https://github.com/users/Lagavulin9/projects/2)

## Architecture

!! Add a diagram of the architecture here. !! <br>
!! SAME AS THE ONE IN THE DOCUMENTATION that will be in software-strucutre.md !! <br>

## Demonstration Video
!! UPLOAD A VIDEO OF THE DEMONSTRATION WITH THE FILENAME "demonstration.gif" !! <br>
<img src="./documentation/images/demonstration.gif" width="40%" margin="120%">

## Known Issues 
Some issues we found while testing. <br>
| Issue | Description |
| --- | --- |


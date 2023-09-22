# **DES Project - Head Unit**
## The head unit Qt application running on Raspberry Pi (RPi) alongside the instrument cluster Qt application  
</br>


# Index
#### [Introduction](#introduction-1)
#### [Background Information](#background-information-1)
#### [Project Goals & Objectives](#project-goals-and-objectives)
#### [Technical Requirements](#technical-requirements-1)
#### [System Architecture](#system-architecture-1)
#### [Implementation](#implementation-1)
#### [Project Timeline](#project-timeline-1)
#### [Collaboration and Teamwork](#collaboration-and-teamwork-1)
#### [Mentorship and Support](#mentorship-and-support-1)
#### [Reflection and Self-Assessment](#reflection-and-self-assessment-1)
#### [Results](#results-1)
#### [Submission](#submission-1)
#### [References](#references-1)
</br>


 s
# Introduction

This project aims to develop a Head Unit Qt application running on a Raspberry Pi (RPi) alongside the previously developed PiRacer Instrument Cluster Qt application. The Head Unit application will provide additional features like ambient lighting, gear selection, and a media app. The project will use Yocto as the build system for the RPi.  
</br>


# Background Information

The PiRacer is an autonomous racing car that uses a Raspberry Pi as the central control unit. The previous project, the PiRacer Instrument Cluster Qt application, was developed to display real-time speed data from the speed sensor on the car. This project aims to expand on the previous project and provide additional functionality for the PiRacer.

The automotive and mobility industry is undergoing a significant transformation with the introduction of advanced technologies and software systems. With the increasing demand for connected, safe, and efficient vehicles, software has become an essential part of modern automobiles. To meet the demands of this dynamic industry, software engineers need to have a deep understanding of the specific requirements and challenges of developing software for vehicles.

The Raspberry Pi (RPi) platform is a popular, low-cost, and versatile computing platform that is well suited for a wide range of applications, including embedded systems. The Yocto project is an open-source project that provides a complete embedded Linux distribution, including all the tools, libraries, and technologies needed to develop custom Linux-based systems.

The head unit application is a critical component of the in-car infotainment system, providing a user interface for various functions, such as ambient lighting, gear selection, and media playback. The goal of this peer-peer educational project is to develop a head unit Qt application that runs on the RPi, using the Yocto project for embedded Linux development.

The implementation of the head unit application will involve integrating various components and systems, such as the ambient lighting, gear selection, and media app, to create a seamless and intuitive user experience. To ensure the safety and reliability of the system, careful consideration will be given to the software design and implementation, as well as the testing and validation of the application.  
</br>


# Project Goals and Objectives

Goals:

1. Develop a robust and scalable head unit application for automotive use on Raspberry Pi.
2. Integrate the application with the instrument cluster app and other vehicle systems through IPC (Inter-Process Communication) and CAN (Controller Area Network).
3. Implement user-friendly and interactive features such as ambient lighting, gear selection, and media app.
4. Utilize Yocto for creating a stable and customizable embedded Linux operating system for the project.

Objectives:

1. Design and implement a system architecture that meets the project requirements and integrates with other vehicle systems.
2. Write efficient and high-quality code for the head unit application and its features.
3. Test and validate the application to ensure its reliability, performance, and compatibility with the vehicle environment.
4. Document the project and its outcomes to provide a reference for future development and maintenance.

</br>


# Technical Requirements

* Development of a Head Unit Qt application for the Raspberry Pi, running alongside the PiRacer Instrument Cluster Qt application.
* Implementation of ambient lighting control through the Head Unit application.
* Display of the current gear selection on the Head Unit GUI.
* Development of a media app, including functionality for playing and controlling music and videos.
* Use of Yocto as the build system for the Raspberry Pi.

</br>


# System Architecture

The system architecture of the head unit Qt application running on Raspberry Pi (RPi) alongside the instrument cluster application, aims to provide an integrated solution for in-car entertainment, lighting, and driving-related information. It includes various functional components such as the media player, ambient lighting, gear selection, and data acquisition from other onboard systems.

The central component of the architecture is the RPi, running a Yocto-based operating system, which acts as the main platform for the instrument cluster and head unit application. The instrument cluster and head unit applications communicate with each other through the IPC (eg. VSOMEIP, dbus, AUTOSAR interface middleware) which allows for the exchange of data and information between the two applications.

The media player component is responsible for playing audio and video files, as well as supporting features like Bluetooth connectivity and audio output. The ambient lighting component provides a customisable lighting solution for the interior of the car, which can be configured to match the user's preferences. The gear selection component enables the user to control the gear selection mechanism in the car, which includes features like automatic gear detection, manual gear selection, and gear shift mode. The data acquisition component integrates with other onboard systems, such as the speed sensor, to provide up-to-date information to the user.

Overall, the system architecture is designed to provide a flexible and scalable solution that can be easily adapted to the needs of the user. By using the latest technologies and industry standards, the head unit and instrument cluster applications can provide a highly integrated and user-friendly experience for the driver and passengers.  
</br>


# Implementation

The implementation of the head unit Qt application on the RPi alongside the instrument cluster app will require the integration of various components, including the use of Yocto as the primary operating system image. The following steps should be taken during the implementation phase:

1. Installation of Yocto on the RPi and setup of the necessary tools and dependencies.
2. Development of the head unit Qt application and its integration with the instrument cluster app. This will include the implementation of features such as ambient lighting, gear selection, and media app.
3. Communication between the head unit and the instrument cluster app will be established using IPC such as vsomeip/autosar.
4. The head unit will receive speed data from the speed sensor via CAN, and this data will be processed and displayed on the head unit's display.
5. Testing and debugging of the entire system to ensure it meets the technical requirements and operates as expected.
6. Final integration and deployment of the head unit and instrument cluster app on the RPi, ready for use in a real-world automotive environment.

Throughout the implementation phase, a systematic approach to software development will be taken, following best practices in software engineering to ensure the final product is of high quality and reliable.  
</br>


# Project Timeline

* Requirements gathering and system architecture design - 1 week
* Development of head unit application and its features - 4 weeks
* Integration with vehicle systems and testing - 1 week
* Documentation and final evaluation - 1 week

Note: This timeline is an estimate and may change based on the actual progress and complexities encountered during the project. The project team will regularly review the timeline and make adjustments as necessary to ensure the project is completed on time and within scope.  
</br>


# Collaboration and Teamwork

Students will be working in teams of maximum four to complete this project. Each team member will be assigned specific tasks and responsibilities, and will be expected to contribute to the overall success of the project. Teams will be required to submit regular progress reports and to meet with the instructor for check-ins and feedback.  
</br>


# Mentorship and Support

Students will be provided with mentorship and support from the instructor throughout the project. The instructor will be available for questions and guidance, and will hold regular check-ins and progress reports to provide feedback and support.  
</br>


# Reflection and Self-Assessment

Students will be encouraged to reflect on their own learning and progress throughout the project. This will be done through self-assessment exercises and through feedback from the instructor and other team members.  
</br>


# Results

The results of the implementation of the head unit Qt application running on RPi alongside the instrument cluster app will be evaluated based on the following metrics:

1. User Experience: The application will be tested for ease of use, intuitive interface and responsiveness.
2. Ambient lighting: The effectiveness and accuracy of the ambient lighting feature will be evaluated through various tests.
3. Gear selection: The reliability and accuracy of the gear selection feature will be evaluated through various tests.
4. Media App: The performance and compatibility of the media app will be evaluated with various media formats and sources.
5. IPC (Inter-Process Communication): The efficiency and speed of the IPC mechanism used, such as vsomeip/autosar, will be evaluated through performance tests.
6. CAN (Controller Area Network) communication: The reliability and speed of communication between the head unit and the speed sensor will be evaluated through various tests.
7. Yocto compatibility: The compatibility and integration of the head unit application with the Yocto platform will be evaluated.

The results will provide valuable insights into the performance and reliability of the head unit application and the effectiveness of the various technologies and tools used, such as Yocto, IPC and CAN.  
</br>


# Submission

Turn in a github repository with following information:

1. Code and relevant configuration files.
2. Detailed descriptions of algorithms and data structures used in the implementation.
3. Screenshots and diagrams of the head unit user interface.
4. Detailed test plans, test cases, and results of software testing and debugging.
5. Detailed descriptions of the hardware components used in the project, including the Raspberry Pi and the LEDs.
6. A list of online resources and tutorials used in the project.
7. Any additional material that supports the understanding of the project and provides context to the reader.

</br>


# References

* Yocto Project. (2021). Yocto Project. https://www.yoctoproject.org/
* Qt Project. (2021). Qt Project. https://www.qt.io/
* Raspberry Pi Foundation. (2021). Raspberry Pi. [https://www.raspberrypi.org/](https://www.raspberrypi.org/)
* CAN specification documents: These documents provide detailed information on the CAN (Controller Area Network) protocol and its implementation.
* VsomIp/Autosar documents: These documents provide information on the Inter-Process Communication (IPC) frameworks VsomIp and Autosar and their implementation in the automotive industry.


Shield: [![CC BY-NC-SA 4.0][cc-by-nc-sa-shield]][cc-by-nc-sa]

This work is licensed under a
[Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License][cc-by-nc-sa].

[![CC BY-NC-SA 4.0][cc-by-nc-sa-image]][cc-by-nc-sa]

[cc-by-nc-sa]: http://creativecommons.org/licenses/by-nc-sa/4.0/
[cc-by-nc-sa-image]: https://licensebuttons.net/l/by-nc-sa/4.0/88x31.png
[cc-by-nc-sa-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg

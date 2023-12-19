
# Can Communication

!! UNDER CONSTRUCTION !!

## Table of Contents
- [Intro](#intro)
- [Project Structure](#project-structure)
- [Methodology](#methodology)
- [Moving Average Filter](#moving-average-filter)
- [References](#references)


## Intro

The main objective of the project is to transform CAN data received from Arduino into a socket format and then use vSomeIP to enable other applications to access Speed and RPM data in real-time.
```
.
├── CMakeLists.txt
├── fidl
│   ├── CanReceiver.fdepl
│   └── CanReceiver.fidl
├── scripts
│   ├── Build.sh
│   └── Run.sh
├── src
│   ├── CanDataRegister.cpp
│   ├── CanDataRegister.hpp
│   ├── CanReceiver.cpp
│   ├── CanReceiver.hpp
│   ├── main.cpp
│   ├── MovingAverageFilter.cpp
│   ├── MovingAverageFilter.hpp
│   ├── SpeedSensorStubImpl.cpp
│   └── SpeedSensorStubImpl.hpp
├── src-gen
│   ├── core
│   │   └── v0
│   │       └── commonapi
│   │           ├── SpeedSensor.hpp
│   │           ├── SpeedSensorProxyBase.hpp
│   │           ├── SpeedSensorProxy.hpp
│   │           ├── SpeedSensorStubDefault.hpp
│   │           └── SpeedSensorStub.hpp
│   └── someip
│       └── v0
│           └── commonapi
│               ├── SpeedSensorSomeIPCatalog.json
│               ├── SpeedSensorSomeIPDeployment.cpp
│               ├── SpeedSensorSomeIPDeployment.hpp
│               ├── SpeedSensorSomeIPProxy.cpp
│               ├── SpeedSensorSomeIPProxy.hpp
│               ├── SpeedSensorSomeIPStubAdapter.cpp
│               └── SpeedSensorSomeIPStubAdapter.hpp
```

### Project Structure

The project directory is structured as follows:

- `CMakeLists.txt`: Contains the CMake configuration for building the project.
- `fidl`:
  - `CanReceiver.fdepl`: Deployment file for the CAN Receiver.
  - `CanReceiver.fidl`: FIDL (Franca IDL) interface description for the CAN Receiver.
- `scripts`:
  - `Build.sh`: Script to build the project.
  - `Run.sh`: Script to run the project.
- `src`: Source code directory containing core functionality files.
- `src-gen`: Generated source code directory containing Common API core components and SOME/IP specific components.

### Methodology

The core functionality of the project involves receiving CAN data, processing it, and sending it using vSomeIP. The methodology used in the code is as follows:

- **CAN Data Reception and Processing**: 
  - The `CanReceiver` class is responsible for opening a socket to receive CAN data (`openPort`), reading this data from the socket (`readData` ), and processing it (`processAndFilterData` ). 
  - It uses a moving average filter implemented in `MovingAverageFilter.cpp` and `MovingAverageFilter.hpp` to smooth the received RPM data.
  - The calculated speed and RPM are then prepared for transmission.

- **Transmission Using vSomeIP**:
  - The `CanDataRegister` class manages the transmission of processed data using the vSomeIP protocol.
  - It initializes a vSomeIP service (`SpeedSensor_Init` ) and registers it with the CommonAPI runtime.
  - Processed speed and RPM data are sent using the `sendDataToVSomeIP` method, which sets these values in the `SpeedSensorStubImpl` instance.
 
  - ***For more detail about vsome/ip & common api***
    - [common_api.md](https://github.com/Lagavulin9/DES_Head-Unit/blob/documentation/documentation/common_api.md)

This design allows for efficient reception of raw data from a CAN interface, its processing, and then transmission using vSomeIP protocol, integrating automotive communication standards.

## Moving Average Filter

### Implementation

The Moving Average Filter is implemented in `MovingAverageFilter.cpp` and `MovingAverageFilter.hpp`. This class uses a queue to store a fixed number of the most recent values and computes the average of these values, discarding the oldest values as new ones come in.

### Usage Rationale

The Moving Average Filter is used to smooth out short-term fluctuations and highlight longer-term trends or cycles in the data. In the context of this project, it helps in reducing the noise in the incoming RPM data from the CAN interface, leading to more stable and reliable speed calculations.

### Advantages

- **Noise Reduction**: Effectively reduces random variability in the data.
- **Simplicity**: Easy to implement and understand.
- **Efficiency**: Suitable for real-time data processing with minimal computational load.

### Disadvantages

- **Lag**: Introduces a delay in the response, as it relies on past data.
- **Data Loss**: Initial data points are not utilized effectively as the filter reaches its full size.
- **Edge Effects**: Can produce misleading results at the beginning and end of the data set.


## References
[CAN HAT](https://github.com/Seeed-Studio/Seeed_Arduino_CAN)  
[Moving-Average-Filter](https://www.analog.com/media/en/technical-documentation/dsp-book/dsp_book_ch15.pdf)


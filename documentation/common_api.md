# Common API & vSOME/IP 

## Table of Contents


## Notation vSOME/IP
The used notation on the vSOME/IP interface is set in the dfidl files of each application. <br>
### Conventions: 
- IDs binded to the sequence number of the application 
    - 1 = Head_Unit 
    - 2 = Dashboard 
    - 3 = Can_Speedsensor 
    - 4 = Car_Control 
    - 5 = Car_Info
- 0x | App. sequence number | Eventgroup | Event ID | 
- Reliable mode = on
- Network: 
    - IP: 192.168.0.2 
    - Port: Starts with applications sequence number and ends with 0 or 1. 
        - 0 = Reliable
        - 1 = Unreliable

#### 1) Head_Unit
```yaml
    test
```

#### 2) Dashboard
```yaml
    test
```


#### 3) Can_Speedsensor
```yaml
interface Can_Receiver.Speed_Sensor:
    SomeIpServiceID = 0x3000
    attribute speed {
        SomeIpGetterID              = 0x3101
        SomeIpSetterID              = 0x3102
        SomeIpNotifierID            = 33104
        SomeIpAttributeReliable     = false
        SomeIpNotifierEventGroups   = 33104
    attribute rpm {
        SomeIpGetterID              = 0x3201
        SomeIpSetterID              = 0x3202
        SomeIpNotifierID            = 33204
        SomeIpAttributeReliable     = false
        SomeIpNotifierEventGroups   = 33204
Service:
        InstanceId = "Speed_Sensor"
        SomeIpInstanceID = 22000
```
#### 4) Car Control:

```yaml
SomeIpServiceID = 4000
    attribute indicator:
        SomeIpNotifierEventGroups   = 4100
        SomeIpNotifierID            = 41000
        SomeIpGetterID              = 4101
        SomeIpAttributeReliable     = true
    attribute gear 
        SomeIpNotifierEventGroups   = 4200 
        SomeIpNotifierID            = 42000
        SomeIpGetterID              = 4201
    method gearSelectionHeadUnit 
        SomeIpMethodID              = 4200
Service: 
        InstanceId                  = "commonapi.CarControl"
        SomeIpInstanceID            = 4001
        SomeIpUnicastAddress        = "192.168.0.2"
        SomeIpReliableUnicastPort   = 40010
        SomeIpUnreliableUnicastPort = 40011
```

#### 5) Car_info: 

```yaml
interface commonapi.CarInfo:
    SomeIpServiceID = 5000
    attribute battery
        SomeIpNotifierEventGroups   = 5100
        SomeIpNotifierID            = 51000
        SomeIpGetterID              = 5101
        SomeIpAttributeReliable     = true

Service:
    InstanceId                      = "commonapi.CarInfo"
    SomeIpInstanceID                = 5001
    SomeIpUnicastAddress            = "192.168.0.2"
    SomeIpReliableUnicastPort       = 50010
    SomeIpUnreliableUnicastPort     = 50011
```

# CommonAPI vSomeIP Setup (RPi 4B)

https://github.com/SEA-ME/Team-Pilot/tree/Moon/Project-2/CommonAPI-vSomeIP

- Step 1: Install Dependencies 
Java 8, Boost-dev, libdbus and ascii are required. 
See Some/IP documentations for more informations. 
```bash
sudo apt update
sudo apt install openjdk-8-jdk
sudo apt-get install libboost-all-dev
sudo apt-get install libdbus-1-dev
sudo apt install ascii
```
Additionally, the piracer's drivetrain and battery control unit needs some python dependencies.
Install piracer-py package globally (not recommended). 
```bash
pip install piracer-py
```

- Step 3: Build & Install the CommonAPI Core Runtime Library
```bash
cd ~
git clone https://github.com/GENIVI/capicxx-core-runtime.git
cd capicxx-core-runtime/
mkdir build
cd build
cmake ..
make 
sudo make install
```

- Step 4: Build & Install the vSomeIP Library
```bash
cd ~
git clone https://github.com/COVESA/vsomeip.git
cd vsomeip
mkdir build
cd build
cmake -DENABLE_SIGNAL_HANDLING=1 -DDIAGNOSIS_ADDRESS=0x10 ..
make
sudo make install
```

- Step 5: Build the CommonAPI SOME/IP Runtime Library
```bash
git clone https://github.com/GENIVI/capicxx-someip-runtime.git
cd capicxx-someip-runtime
mkdir build
cd build
cmake -DUSE_INSTALLED_COMMONAPI=OFF ..
make
sudo make install
```

- Step 6: Write the Franca file 
- Step 7: Generate Code with the CommonAPI Generator
Unfortunately, code generator [doesn’t support arm architecture.]((https://github.com/COVESA/capicxx-core-tools/issues/19)). 
So if you want to use this generator, I recommend that you use the code generator on your own machine or use github actions to generated code. 
The code generator automatically generates codes according to fidl and fdepl files. In the case of vsomeip binding, you have to run it twice with core-generator and some-generator to complete it.

CORE TOOL:  https://github.com/COVESA/capicxx-core-tools
VSOME TOOL: https://github.com/COVESA/capicxx-someip-tools
SEE: https://github.com/SEA-ME-COSS/DES-Head-Unit/tree/main/setting
Unfornauteley, the generator does not run on the target system (Raspberry Pi). Therefore, the teams laptop or ci automation (github action) can be used.

```bash
/home/seame02/generator/core-generator/commonapi-core-generator-linux-x86_64 -sk ./fidl/carinfo.fidl -d ./src-gen-carinfo/core
/home/seame02/generator/someip-generator/commonapi-someip-generator-linux-x86_64  ./fidl/carinfo.fdepl -d ./src-gen-carinfo/someip
```
### Binding to vSOME/IP 
// https://github.com/SEA-ME/Team-Pilot/tree/Moon/Project-2/CommonAPI-vSomeIP
CommonAPI and available bindings can be configured by ini-files (see e.g. http://en.wikipedia.org/wiki/INI_file).
The CommonAPI configuration file is commonapi.ini. There are three places where CommonAPI Runtime tries to find this
file (in the following order):
1. in the directory of the current executable. If there is a commonapi.ini file, it has the highest priority.
2. in the directory which is specified by the environment variable COMMONAPI_CONFIG.
3. in the global default directory /etc.
The configuration file has 4 possible sections; all sections are optional.
The default default binding is "dbus". This can be changed by setting the "binding" variable in the "default"-section of the CommonAPI configuration file or by setting the environment variable "COMMONAPI_DEFAULT_BINDING". The environment variable overwrites the setting provided by the configuration file.
Write CommonAPI Configuration Files

## Reference
- [CommonAPI SomeIP in 10-minutes](https://github.com/COVESA/capicxx-someip-tools/wiki/CommonAPI-C---SomeIP-in-10-minutes)
- [How to Install Java on Raspberry Pi](https://phoenixnap.com/kb/install-java-raspberry-pi#ftoc-heading-4)
- [How to install latest Boost library on Raspberry Pi](http://osdevlab.blogspot.com/2016/02/how-to-install-latest-boost-library-on.html)
- [CommonAPI C++ User Guide (most helpful)](https://usermanual.wiki/Document/CommonAPICppUserGuide.113855339.pdf)
---
[**commonapi user guide**](https://usermanual.wiki/Document/CommonAPICppUserGuide.113855339.pdf) If you do not know something, it is recommended to find it here first.

https://github.com/Pelagicore/common-api-tools/tree/master/CommonAPI-Examples/E02Attributes
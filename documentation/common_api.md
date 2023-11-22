# Setup PI

## setting binding to vsomeip 
// https://github.com/SEA-ME/Team-Pilot/tree/Moon/Project-2/CommonAPI-vSomeIP
The default default binding is "dbus". This can be changed by setting the "binding" variable in the "default"-section of the CommonAPI configuration file or by setting the environment variable "COMMONAPI_DEFAULT_BINDING". The environment variable overwrites the setting provided by the configuration file.
// Code vsome template: https://github.com/Pelagicore/common-api-tools/tree/master/CommonAPI-Examples/E02Attributes
Write CommonAPI Configuration Files
CommonAPI and available bindings can be configured by ini-files (see e.g. http://en.wikipedia.org/wiki/INI_file).
The CommonAPI configuration file is commonapi.ini. There are three places where CommonAPI Runtime tries to find this
file (in the following order):
1. in the directory of the current executable. If there is a commonapi.ini file, it has the highest priority.
2. in the directory which is specified by the environment variable COMMONAPI_CONFIG.
3. in the global default directory /etc.
The configuration file has 4 possible sections; all sections are optional

## vSOME/IP
- setup vSome ip (see documentations & dockerfile from johang)
https://github.com/SEA-ME/Team-Pilot/tree/Moon/Project-2/CommonAPI-vSomeIP

## SYSTEM DEPENCENDIES  
See Some ip documentations & dockerfile from johang 
https://github.com/SEA-ME/Team-Pilot/tree/Moon/Project-2/CommonAPI-vSomeIP
Java 8, Boost-dev, libdbus and ascii 
```bash
sudo apt update
sudo apt install openjdk-8-jdk
sudo apt-get install libboost-all-dev
sudo apt-get install libdbus-1-dev
sudo apt install ascii
```
Install python dependencies globally - not recommended
```bash
pip install piracer-py
```
## DEPENCENDIES for COMMONAPI & vSOME/IP 
ASSUME TO INSTALL IN HOME DIRECTORY
https://github.com/COVESA/capicxx-someip-tools/wiki/CommonAPI-C---SomeIP-in-10-minutes#step3
https://github.com/COVESA/capicxx-dbus-tools/wiki/CommonAPI-C---D-Bus-in-10-minutes

## CommonAPI Core Runtime Library 
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
###### vSOME/IP Library
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
###### CommonAPI SOMEip Runtime Library 
```bash
git clone https://github.com/GENIVI/capicxx-someip-runtime.git
cd capicxx-someip-runtime
mkdir build
cd build
cmake -DUSE_INSTALLED_COMMONAPI=OFF ..
make
sudo make install
```
################# COMMONAPI generator #################
ASSUME TO INSTALL IN HOME DIRECTORY
CORE TOOL:  https://github.com/COVESA/capicxx-core-tools
VSOME TOOL: https://github.com/COVESA/capicxx-someip-tools
SEE: https://github.com/SEA-ME-COSS/DES-Head-Unit/tree/main/setting
This needs to be run before running Build.sh
Unfornauteley, the generator does not run on the target system (Raspberry Pi). Therefore, the teams laptop or ci automation (github action) can be used.

```bash
#!/bin/bash
#delete "src-gen-carinfo" folder if it exists
if [ -d "src-gen-carinfo" ]; then
    rm -rf src-gen-carinfo
fi
#run generator
/home/seame02/generator/core-generator/commonapi-core-generator-linux-x86_64 -sk ./fidl/carinfo.fidl -d ./src-gen-carinfo/core
/home/seame02/generator/someip-generator/commonapi-someip-generator-linux-x86_64  ./fidl/carinfo.fdepl -d ./src-gen-carinfo/someip
```


####################################################### SOURCE: MOONs Repo #######################################################

# CommonAPI vSomeIP Setup (RPi 4B)

https://github.com/SEA-ME/Team-Pilot/tree/Moon/Project-2/CommonAPI-vSomeIP

## Step 1: Install OpenJDK Java 8
## Step 2: Install Boost.Asio library
## Step 3: Build the CommonAPI Runtime Library
## Step 4: Build the vsomeip Library
## Step 5: Build the CommonAPI SOME/IP Runtime Library
## Step 6: Write the Franca file 
## Step 7: Generate Code
Unfortunately, code generator [doesn’t support arm architecture.]((https://github.com/COVESA/capicxx-core-tools/issues/19)). 
So if you want to use this generator, I recommend that you use the code generator on your own machine or use github actions to generated code. 
The code generator automatically generates codes according to fidl and fdepl files. In the case of vsomeip binding, you have to run it twice with core-generator and some-generator to complete it.

## Reference
- [CommonAPI SomeIP in 10-minutes](https://github.com/COVESA/capicxx-someip-tools/wiki/CommonAPI-C---SomeIP-in-10-minutes)
- [How to Install Java on Raspberry Pi](https://phoenixnap.com/kb/install-java-raspberry-pi#ftoc-heading-4)
- [How to install latest Boost library on Raspberry Pi](http://osdevlab.blogspot.com/2016/02/how-to-install-latest-boost-library-on.html)
- [CommonAPI C++ User Guide (most helpful)](https://usermanual.wiki/Document/CommonAPICppUserGuide.113855339.pdf)
---
[**commonapi user guide**](https://usermanual.wiki/Document/CommonAPICppUserGuide.113855339.pdf) If you do not know something, it is recommended to find it here first.
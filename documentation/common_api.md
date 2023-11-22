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

## Contents
- [Step 1: Install OpenJDK Java 8 on Raspberry Pi](#step-1-install-openjdk-java-8-on-raspberry-pi)
- [Step 2: Install Boost.Asio library](#step-2-install-boostasio-library)
- [Step 3: Build the CommonAPI Runtime Library](#step-3-build-the-commonapi-runtime-library)
- [Step 4: Build the vsomeip Library](#step-4-build-the-vsomeip-library)
- [Step 5: Build the CommonAPI SOME/IP Runtime Library](#step-5-build-the-commonapi-someip-runtime-library)
- [Step 6: Write the Franca file and generate code](#step-6-write-the-franca-file-and-generate-code)
- [Step 7: Write the client and the service application](#step-7-write-the-client-and-the-service-application)
- [Step 8: Build and run](#step-8-build-and-run)
- [Step 9: Client Service Architecture](#step-9-client-service-architecture)

---

<br/>

## Reference
- [CommonAPI SomeIP in 10-minutes](https://github.com/COVESA/capicxx-someip-tools/wiki/CommonAPI-C---SomeIP-in-10-minutes)
- [How to Install Java on Raspberry Pi](https://phoenixnap.com/kb/install-java-raspberry-pi#ftoc-heading-4)
- [How to install latest Boost library on Raspberry Pi](http://osdevlab.blogspot.com/2016/02/how-to-install-latest-boost-library-on.html)
- [CommonAPI C++ User Guide (most helpful)](https://usermanual.wiki/Document/CommonAPICppUserGuide.113855339.pdf)
---

<br/>

## Step 1: Install OpenJDK Java 8 on Raspberry Pi
- **OpenJDK** – An open-source Java environment, licensed under the GNU General Public License.
- **Oracle Java** – A paid service that includes support options and licensing. (most are not compatible with Raspberry Pi)
JRE: Java Runtime Environment (for running Java applications)
```bash
sudo apt update
sudo apt install openjdk-8-jdk
```

You can check installation

```bash
java --version
```

If you have installed both OpenJDK 8 and 11, your default version will OpenJDK 11.
![Untitled](https://user-images.githubusercontent.com/111988634/197338445-baf28b79-91c1-4ca6-9c7b-ce712df4a6f3.png)
To manually set a Java version, start by running the following command

```bash
sudo update-alternatives --config java
```

Select number and set OpenJDK 8 as the system default
![Untitled (1)](https://user-images.githubusercontent.com/111988634/197338474-65925e4a-955d-4090-9a57-9f0a77b68ada.png)
```bash
java -version
```
![Untitled (2)](https://user-images.githubusercontent.com/111988634/197338489-1a2453f9-5618-4ef7-95f1-0b1ab567c4c1.png)

<br/>

## Step 2: Install Boost.Asio library
Install Boost-dev
```bash
sudo apt-get install libboost-all-dev
```

<br/>

## Step 3: Build the CommonAPI Runtime Library

Make working directory. In my case `build-commonapi`

```bash
cd ~
mkdir build-commonapi && cd build-commonapi
```

Start with fetching the source code of CommonAPI:

```bash
git clone https://github.com/GENIVI/capicxx-core-runtime.git
cd capicxx-core-runtime/
git checkout 3.2.0
mkdir build
cd build
cmake ..
make -j8
```

Result:

```bash
[100%] Linking C shared library libCommonAPI.so
[100%] Built target CommonAPI
```

<br/>

## Step 4: Build the vsomeip Library

To build the documentation asciidoc, you need followings

```bash
sudo apt-get install asciidoc source-highlight doxygen graphviz libgtest-dev

# Only for Ubuntu
pip3 install asciido
make doc
```

Before download SOME/IP Runtime library, you should download vsomeip. Because CommonAPI C++ SOME/IP need vsomeip.

```bash
git clone https://github.com/COVESA/vsomeip.git
cd vsomeip
git checkout 3.1.20.3
mkdir build
cd build
cmake -DENABLE_SIGNAL_HANDLING=1 -DDIAGNOSIS_ADDRESS=0x10 ..
make -j8
sudo make install
```

![Untitled (2)](https://user-images.githubusercontent.com/111988634/197358973-be132356-d7e0-4d26-b97d-a6d14c48c0a6.png)

<br/>

## Step 5: Build the CommonAPI SOME/IP Runtime Library

Download CommonAPI SOME/IP Runtime Library and change version

```bash
git clone https://github.com/GENIVI/capicxx-someip-runtime.git
cd capicxx-someip-runtime/
git checkout 3.2.0
mkdir build
cd build
cmake -DUSE_INSTALLED_COMMONAPI=OFF ..
make -j8
```

![Untitled (3)](https://user-images.githubusercontent.com/111988634/197358972-14c36a99-5dc8-42a3-ba13-25f5f7f1e685.png)

<br/>

## Step 6: Write the Franca file and generate code

Unfortunately, code generator [doesn’t support arm architecture.]((https://github.com/COVESA/capicxx-core-tools/issues/19)) So if you want to use this generator, I recommend that you use the code generator on your laptop and then download the generated code via Git.
The code generator automatically generates codes according to fidl and fdepl files. In the case of vsomeip, you have to run it twice with core-generator and some-generator to complete it.
<br/>

`PC`

Create commonapi project directory and open Franca IDL

```bash
cd ~
mkdir project-hello
cd project-hello
mkdir fidl
cd fidl
```

A service which instantiates the interface `HelloWorld` provides the function `sayHello` which can be called. Write fidl and fdepl file in fidl directory.

- [HelloWorld.fidl](project-hello/fidl/HelloWorld.fidl)
- [HelloWorld.fdepl](project-hello/fidl/HelloWorld.fdepl)

Download code generator 3.2.0.1

```bash
cd ~
mkdir generator && cd generator
```

```bash
wget https://github.com/COVESA/capicxx-core-tools/releases/download/3.2.0.1/commonapi_core_generator.zip
unzip commonapi_core_generator.zip -d core-generator
cd core-generator
chmod +x commonapi-core-generator-linux-x86_64
```

Download someip code generator 3.2.0.1

```bash
cd ~/generator
wget https://github.com/COVESA/capicxx-someip-tools/releases/download/3.2.0.1/commonapi_someip_generator.zip
unzip commonapi_someip_generator.zip -d someip-generator
cd someip-generator
chmod +x commonapi-someip-generator-linux-x86_64
```

Run generator

```bash
cd ~/project-hello
../generator/core-generator/commonapi-core-generator-linux-x86_64 -sk ./fidl/HelloWorld.fidl -d ./src-gen-hello
../generator/someip-generator/commonapi-someip-generator-linux-x86_64 ./fidl/HelloWorld.fdepl -d ./src-gen-hello
```

Now, send the generated code to Raspberry pi using rsync command line

```bash
cd ~/project-hello
rsync -avz src-gen <user-name>@<IP-address>:<project-directory>
```

In my case

```bash
rsync -avz src-gen-hello moon@192.168.0.105:/home/moon/project-hello
```

<br/>

## Step 7: Write the client and the service application

<br/>

`Raspberry Pi`

```bash
cd ~/project-hello
mkdir src && cd src
```

Make 4 files in src directory

- [HelloWorldClient.cpp](project-hello/src/HelloWorldClient.cpp)
- [HelloWorldService.cpp](project-hello/src/HelloWorldService.cpp)
- [HelloWorldStubImpl.hpp](project-hello/src/HelloWorldStubImpl.hpp)
- [HelloWorldStubImpl.cpp](project-hello/src/HelloWorldStubImpl.cpp)

    
<br/>

## Step 8: Build and run

```bash
cd ~/project-hello
```
Write CMakeLists.txt on proejct directory

 - [CMakeLists.txt](project-hello/CMakeLists.txt)
 
Build and run

```bash
mkdir build
cd build
cmake ..
make
```

```bash
nano commonapi.ini
```

```
[logging]
console=true
file=./mylog.log
dlt=true
level=verbose

[default]
binding=someip
```

```bash
./HelloWorldService &
./HelloWorldClient
```

https://github.com/COVESA/vsomeip/issues/235

<br/>

## Step 9: Client Service Architecture

Now, let's write the code to send and receive CAN data through IPC using the example below. Since CAN must be used, it is cumbersome to use in the host pc. Therefore, only the generator was created on the host PC and then moved to the Raspberry Pi for use.

This code will be used later in the Qt application as it is.

Because of the Client-Service structure, there should be only one Service, and several Qt applications become clients. This is a structure in which one C++ service provides the same data to multiple Qt clients whenever there is a request.

[**commonapi user guide**](https://usermanual.wiki/Document/CommonAPICppUserGuide.113855339.pdf) If you do not know something, it is recommended to find it here first.

If you've ever developed an app, you should definitely apply asynchronous programming here. If you use the attribute example given by the user guide above, it creates asynchronous communication functions on its own.

Create project directory
```bash
cd ~
mkdir project-can
cd project-can
```

Create CommonAPI Configuration file `commonapi.ini`. The file location can be anywhere in the three places. I put in /etc The reason is that you have to type 1 or 2 each time you create a project. /etc is recommended because it is global and will find it for you.

1. build directory with executables (highest priority)
2. COMMONAPI_CONFIG environment variable
3. /etc

```bash
mkdir build
cd build
code /etc/commonapi.ini
```

```bash
[logging]
console=true
file=./mylog.log
dlt=true
level=verbose

[default]
binding=someip
```

Now write the fidl file. It was created by referring to the second example of the CommonAPI user guide, attribute. Based on this file, the generator creates files.

```bash
cd ~/project-can
mkdir fidl
cd fidl
```

- [CAN.fidl](project-can/fidl/CAN.fidl)
- [CAN-SomeIP.fdepl](project-can/fidl/CAN-SomeIP.fdepl)

make codes by generator
```bash
cd ~/project-can
../generator/core-generator/commonapi-core-generator-linux-x86_64 -sk ./fidl/CAN.fidl -d ./src-gen-can
../generator/someip-generator/commonapi-someip-generator-linux-x86_64 ./fidl/CAN-SomeIP.fdepl -d ./src-gen-can
```

Now you can write the C++ code as you like. After running the example, you'll immediately see what I mean. Now, since there is only one client, there seems to be no difference between the attribute example and the helloworld example. However, if there are multiple clients and the value is changed in the client, asynchronous communication must be used as in the attribute example.

```bash
cd ~/project-can
mkdir src
cd src
```

- [CANClient.cpp](project-can/src/CANClient.cpp)
- [CANClient.hpp](project-can/src/CANClient.hpp)
- [CANService.cpp](project-can/src/CANService.cpp)
- [CANService.hpp](project-can/src/CANService.hpp)
- [CANStubImpl.cpp](project-can/src/CANStubImpl.cpp)
- [CANStubImpl.hpp](project-can/src/CANStubImpl.hpp)
- [defs.h](project-can/src/defs.h)
- [ina219.c](project-can/src/ina219.c)
- [ina219.h](project-can/src/ina219.h)

write CMakeLists.txt
```bash
code ~/project-can/CMakeLists.txt
```
- [CMakeLists.txt](project-can/CMakeLists.txt)

build && run
```bash
mkdir ~/project-can/build
cd ~/project-can/build
cmake ..
make -j8
./CANService &
./CANClient
```
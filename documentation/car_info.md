# Car Info

!! UNDER CONSTRUCTION !! <br>

# Tabel of Contents
- [Introduction](#introduction-1)

# Introduction

The following directory tree shows the project structure. <br>
This application uses Convesa's Common API to connect the PiRacer's battery controller to the car's IPC. <br>

```bash
car_info
├── build
├── fidl
│   ├── car_info.fidl
│   ├── car_info.fdepl
├── include
│   ├── CarInfoStubImpl.hpp
│   ├── PiRacer.hpp
├── piracer
│   ├── vehichles.py
├── scripts
│   ├── Build.sh
│   ├── Run_Client.sh
│   ├── Run_Services.sh
├── src
│   ├── CarInfoClient.cpp
│   ├── CarInfoService.cpp
│   ├── CarInfoStubImpl.cpp
│   ├── PiRacer.cpp
├── src-gen/v0/commonapi
│   ├── core
│   │   ├── CarInfo.hpp
│   │   ├── CarInfoProxy.hpp
│   │   ├── CarInfoProxyBase.hpp
│   │   ├── CarInfoStub.hpp
│   │   ├── CarInfoStubDefault.hpp
│   ├── someip
│   │   ├── CarInfoSomeIPDeployment.cpp
│   │   ├── CarInfoSomeIPDeployment.hpp
│   │   ├── CarInfoSomeIPProxy.cpp
│   │   ├── CarInfoSomeIPProxy.hpp
│   │   ├── CarInfoSomeIPStubAdapter.cpp
│   │   ├── CarInfoSomeIPStubAdapter.hpp
├── CMakeLists.txt
├.github
├── workflows
```

## Battery Information Calculation

## Battery Voltage, Current and Power Consumption
The Piracer's battery controller provides the following information:
- Voltage in V
- Current in mA
- Power consumption in W

## Battery Level
The Piracer runs on three Sanyo 18650 lithium-ion batteries. Usually, the battery level of a lithium-ion battery is a complex function of the battery's state of charge (SOC) and the battery's voltage. 
Unfortunately, the Piracer's battery controller does not provide a SOC value. The only information we have is the current voltage in V and the current in mA. 
To get a rough estimate of the battery level, we can use the voltage measurement and reference discharging curve of the battery from [1](https://lygte-info.dk/info/BatteryChargePercent%20UK.html). 

The discharging curve showed in the image below can be approximated by a third-degree polynomial function

y = -691.919 * x^3 + 7991.667 * x^2 + -30541.295 * x + 38661.500 

<img src="images/battery_level_discharge_approximation.png" width="50%" height="50%">

The code to calculate the battery level is shown below:

``` python
import numpy as np
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

# regression polynom third degree 
x = np.array([4.2, 4.1, 4.0, 3.9, 3.8, 3.7, 3.6, 3.5])
y = np.array([100, 91, 79, 62, 42, 12, 2, 0])
z = np.polyfit(x, y, 3)
f = np.poly1d(z)
x_new = np.linspace(x[0], x[-1], 50)
y_new = f(x_new)
plt.plot(x,y,'o', x_new, y_new)
plt.xlim([x[0]-1, x[-1] + 1 ])
plt.title('Battery Level (Regression, Third Degree)', fontsize=12)
plt.xlabel("Voltage (V)")
plt.ylabel("Battery Level (%)")
plt.grid()
plt.legend()
# add texfield to figure
plt.text(3.2, 100, f"y = {z[0]:.3f} * x^3 + {z[1]:.3f} * x^2 + {z[2]:.3f} * x + {z[3]:.3f}", fontsize=8)
plt.show()
print(f"y = {z[0]:.3f} * x^3 + {z[1]:.3f} * x^2 + {z[2]:.3f} * x + {z[3]:.3f}")
```
## CommonAPI
The communication between the Head Unit and the Car Control is based on the vSOME/IP protocol. <br>
The applications "Head_Unit" and "Dashboard" acts as a clients and  "Car_Control" is the service. <br>
Both clients are subscripted to the service's events. 
The service interface contains a struct attribute "battery" that contains float voltage, current, power consumption. <br>

```ruby
interface CarInfo {
    version { major 0 minor 1 }
    attribute CommonTypes.batteryStruct battery readonly
}
typeCollection CommonTypes {
    version { major 0 minor 1 }
    struct batteryStruct {
        Float level
        Float consumption
        Float current
        Float voltage
    }
}
```
Since, the attribute readonly, the service is responsible to update the attribute's value and notify the client about the change. The value is updated every second. <br>
```cpp
 ---------------------------
Received change message for battery
    level      : 0.784
    voltage    : 12.600
    consumption: 4.234
    current    : 201.222
 ---------------------------
  ```
# Reference
[1](https://lygte-info.dk/info/BatteryChargePercent%20UK.html)

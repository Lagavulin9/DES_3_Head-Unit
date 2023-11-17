# Notation vSOME/IP

The used notation on the vSOME/IP interface is set in the .dfidl files of each application. <br>

# Conventions: 
- IDs binded to the sequence number of the application 
    - 1 = Head_Unit, 2 = Dashboard, 3 = Can_Speedsensor, 4 = Car_Control, 5 = Car_Info
- The InstanceID is set to the name of the application.
- 0x |App. sequence number | Eventgroup | Event ID | 
- Reliable mode of all SomeIp attributes should active. 
- Network: 
    - IP: 192.168.0.2 
    - Port: Starts with applications sequence number and ends with 0 or 1. 
        - 0 = Reliable
        - 1 = Unreliable

# 1) Head_Unit: 


# 2) Dashboard: 


# 3) Can_Speedsensor: 
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
# 4) Car Control:

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

# 5) Car_info: 

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
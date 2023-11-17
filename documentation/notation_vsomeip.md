The used notation on the vSOME/IP interface is set in the dfidl files of each application. 
All SomeIp Attribute are set to reliable mode true. 

# Car Control:
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

# Car_info: 
```yaml
interface commonapi.CarInfo:
    SomeIpServiceID = 5000
    attribute battery
        SomeIpNotifierEventGroups   = 5100
        SomeIpNotifierID            = 51000
        SomeIpGetterID              = 5101

Service:
    InstanceId                      = "commonapi.CarInfo"
    SomeIpInstanceID                = 5001
    SomeIpUnicastAddress            = "192.168.0.2"
    SomeIpReliableUnicastPort       = 50010
    SomeIpUnreliableUnicastPort     = 50011
```

# Can Speedsensor: 
```yaml
import "platform:/plugin/org.genivi.commonapi.someip/deployment/CommonAPI-4-SOMEIP_deployment_spec.fdepl"
import "Can_Receiver.fidl"

define org.genivi.commonapi.someip.deployment for interface Can_Receiver.Speed_Sensor {
    SomeIpServiceID = 0x3000
    

    attribute speed {
        SomeIpGetterID = 0x3101
        SomeIpSetterID = 0x3102
        SomeIpNotifierID = 33104
        SomeIpAttributeReliable = false
        SomeIpNotifierEventGroups = { 33104 }
    }

    attribute rpm {
        SomeIpGetterID = 0x3201
        SomeIpSetterID = 0x3202
        SomeIpNotifierID = 33204
        SomeIpAttributeReliable = false
        SomeIpNotifierEventGroups = { 33204 }
    }
}

define org.genivi.commonapi.someip.deployment for provider as Service {
    instance Can_Receiver.Speed_Sensor {
        InstanceId = "Speed_Sensor"

        SomeIpInstanceID = 22000
    }
}
```
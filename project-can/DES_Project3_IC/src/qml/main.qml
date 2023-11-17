import QtQuick 2.15
import QtQuick.Window 2.15
import ICdatamanager 1.0

Window {
    id: instrumentCluster
    width: 1280
    height: 400
    visible: true

    property int rpm: 0
    property int speed: 0
    property string gear: "P"
    property double current: 0.0
    property double powerConsumption: 0.0
    property double voltage: 0.0
    property int battery: 0
    

    Loader{
        width: parent.width
        height: parent.height
        source: "Background.qml"
        active: true
    }

    // Left QML Section (Battery.qml)
    Loader {
        x: 0
        y: 0
        width: parent.width / 3
        height: parent.height
        source: "BatteryBar.qml"
        active: true
        onLoaded:{
            item.battery = instrumentCluster.battery
        }
    }
    Loader {
        x: 0
        y: 0
        width: parent.width / 3
        height: parent.height * (2/3)
        source: "BatteryValue.qml"
        active: true
        onLoaded:{
            item.powerConsumption = instrumentCluster.powerConsumption
            item.voltage = instrumentCluster.voltage
            item.current = instrumentCluster.current
        }
    }

    // Middle QML Section (CentralCar.qml)
    Loader{
        x: parent.width / 3
        y: 0
        width: parent.width/3
        height: parent.height
        source: "Gear.qml"
        active: true
        onLoaded:{
            item.gearState = instrumentCluster.gear
        }

    }
    Loader{
        x: parent.width / 3
        y: parent.height / 3
        width: parent.width / 3
        height: parent.height /3
        source: "Speed.qml"
        active: true
        onLoaded:{
            item.rpm = instrumentCluster.rpm
            item.speed = instrumentCluster.speed
        }
    }

    Loader {
        x: parent.width / 3
        y: 0
        width: parent.width / 3
        height: parent.height
        source: "CentralCar.qml"
        active: true
    }

    // Third QML Section (Media.qml)
    Loader {
        x: (parent.width / 3) * 2
        y: 0
        width: parent.width / 3
        height: parent.height / 5
        source: "Time.qml"
        active: true
    }

    Loader {
        x: (parent.width / 3) * 2
        y: parent.height / 5
        width: parent.width / 3
        height: parent.height * 3 / 5
        source: "MediaAlbum.qml"
        active: true
    }

    Loader {
        x: (parent.width / 3) * 2
        y: parent.height * 4 / 5
        width: parent.width / 3
        height: parent.height / 5
        source: "MediaLyrics.qml"
        active: true
    }
    ICdatamanager{
        id: icdatamanager

        onRpmChanged: {instrumentCluster.rpm = rpm}
        onSpeedChanged: {instrumentCluster.speed = speed}
        onGearChanged: {instrumentCluster.gear = gear}
        onCurrentChanged: {instrumentCluster.current = current}
        onPowerConsumptionChanged: {instrumentCluster.powerConsumption = powerConsumption}
        onVoltageChanged: {instrumentCluster.voltage = voltage}
        onBatteryChanged: {instrumentCluster.battery = battery}

    }


}



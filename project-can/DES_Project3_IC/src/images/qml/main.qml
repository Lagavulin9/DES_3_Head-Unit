import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 1280
    height: 400
    visible: true
    title: qsTr("Head_Unit_Instrument_Cluster")

    Loader{
        width: parent.width
        height: parent.height
        source: "Background.qml"
    }

    // Left QML Section (Battery.qml)
    Loader {
        x: 0
        y: 0
        width: parent.width / 3
        height: parent.height
        source: "BatteryBar.qml"
    }
    Loader {
        x: 0
        y: 0
        width: parent.width / 3
        height: parent.height * (2/3)
        source: "BatteryValue.qml"
    }

    // Middle QML Section (CentralCar.qml)
    Loader{
        x: parent.width / 3
        y: 0
        width: parent.width/3
        height: parent.height
        source: "Gear.qml"

    }
    Loader{
        x: parent.width / 3
        y: parent.height / 3
        width: parent.width / 3
        height: parent.height /3
        source: "Speed.qml"
    }

    Loader {
        x: parent.width / 3
        y: 0
        width: parent.width / 3
        height: parent.height
        source: "CentralCar.qml"
    }

    // Third QML Section (Media.qml)
    Loader {
        x: (parent.width / 3) * 2
        y: 0
        width: parent.width / 3
        height: parent.height / 5
        source: "Time.qml"
    }

    Loader {
        x: (parent.width / 3) * 2
        y: parent.height / 5
        width: parent.width / 3
        height: parent.height * 3 / 5
        source: "MediaAlbum.qml"
    }

    Loader {
        x: (parent.width / 3) * 2
        y: parent.height * 4 / 5
        width: parent.width / 3
        height: parent.height / 5
        source: "MediaLyrics.qml"
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.1}
}
##^##*/

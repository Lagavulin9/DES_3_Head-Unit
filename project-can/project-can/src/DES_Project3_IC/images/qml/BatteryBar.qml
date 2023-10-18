import QtQuick 2.15

Item {
    width: parent.width
    height: parent.height / 3

    property int batteryValue: 100

    Rectangle {  // Background color
        anchors.fill: parent
        color: "#E1E1E1"
    }

    Rectangle {
        id: batteryBar
        x: 127
        y: 50
        width: parent.width * (batteryValue / 100) / 3
        height: 20
        color: "green"

        Behavior on width {
            NumberAnimation { duration: 1000 }
        }
    }

    Text {
        x: 275
        y: 51
        font.family: "Kanit"
        font.pixelSize: 16
        font.bold: true
        text: batteryValue + "%"
    }

    Image {
        x: 104
        y: 46
        width: 23
        height: 24
        source: "images/elec_car.png"
    }
}

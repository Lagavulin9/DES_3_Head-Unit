import QtQuick 2.15

Item {
    width: parent.width
    height: parent.height * 2 / 3

    property real speedValue: 60  // Example speed value

    Text {
        id: speedText
        anchors.centerIn: parent
        font { family: "Kanit"; pixelSize: 96; bold: true }
        text: speedValue
        color: "black"
    }

    Text {
        id: speedUnit
        anchors { top: speedText.bottom; horizontalCenter: speedText.horizontalCenter }
        font { family: "Kanit"; pixelSize: 24; bold: true }
        text: "km/h"
        color: "black"
    }
}



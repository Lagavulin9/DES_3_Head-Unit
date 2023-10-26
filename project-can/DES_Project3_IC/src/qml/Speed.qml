import QtQuick 2.15

Item {
    width: parent.width
    height: parent.height * 2 / 3

    property int rpm : 0
    property int speed : 0
    property int displayValue : instrumentCluster.speed  
    property string displayUnit: "speed"  // Starts with speed

    function toggleDisplay() {
        if (displayUnit === "speed") {
            displayUnit = "rpm";
            displayValue = instrumentCluster.rpm;
        } else {
            displayUnit = "speed";
            displayValue = instrumentCluster.speed;
        }
    }

    Connections {
        target: instrumentCluster
        onSpeedChanged: {
            if (displayUnit === "speed") {
                displayValue = instrumentCluster.speed;
            }
        }
        onRpmChanged: {
            if (displayUnit === "rpm") {
                displayValue = instrumentCluster.rpm;
            }
        }
    }

    Text {
        id: mainValueText
        anchors.centerIn: parent
        font { family: "Kanit"; pixelSize: 96; bold: true }
        text: displayValue
        color: "black"

        MouseArea {
            anchors.fill: parent
            onClicked: toggleDisplay()
        }
    }

    Text {
        id: unitText
        anchors { top: mainValueText.bottom; horizontalCenter: mainValueText.horizontalCenter }
        font { family: "Kanit"; pixelSize: 24; bold: true }
        text: displayUnit
        color: "black"
    }
}

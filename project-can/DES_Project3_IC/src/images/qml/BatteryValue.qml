import QtQuick 2.15

Item {
    width: parent.width
    height: parent.height * 2 / 3

    property real currentValue: 13
    property string currentUnit: "W"

    function switchUnit() {
        if (currentUnit === "W") {
            currentUnit = "V";
            currentValue = 11;
        } else if (currentUnit === "V") {
            currentUnit = "mA";
            currentValue = 1.2;
        } else if (currentUnit === "mA") {
            currentUnit = "W";
            currentValue = 13;
        }
    }

    Text {
        id: mainValue
        anchors { horizontalCenter: parent.horizontalCenter; top: parent.top; topMargin: 156 }
        font { family: "Kanit"; pixelSize: 96; bold: true }
        text: currentValue
        anchors.horizontalCenterOffset: 0
    }

    Text {
        id: unitText
        anchors { horizontalCenter: mainValue.horizontalCenter; top: mainValue.bottom }
        font { family: "Kanit"; pixelSize: 24; bold: true }
        text: currentUnit
    }

    Text {
        id: secondaryText1
        x: 105
        y: 332
        font { family: "Kanit"; pixelSize: 24; bold: true }
        text: currentUnit === "W" ? "11" : (currentUnit === "V" ? "1.2" : "13")
    }

    Text {
        id: secondaryUnitText1
        x: 148
        y: 342
        font { family: "Kanit"; pixelSize: 16; bold: true }
        text: currentUnit === "W" ? "V" : (currentUnit === "V" ? "mA" : "W")
    }

    Text {
        id: secondaryText2
        x: 260
        y: 332
        font { family: "Kanit"; pixelSize: 24; bold: true }
        text: currentUnit === "W" ? "1.2" : (currentUnit === "V" ? "13" : "11")
    }

    Text {
        id: secondaryUnitText2
        x: 308
        y: 340
        font { family: "Kanit"; pixelSize: 16; bold: true }
        text: currentUnit === "W" ? "mA" : (currentUnit === "V" ? "W" : "V")
    }

    MouseArea {
        anchors.fill: mainValue
        anchors.margins: -25
        onClicked: switchUnit()
    }

    Component.onCompleted: switchUnit()
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.1}
}
##^##*/

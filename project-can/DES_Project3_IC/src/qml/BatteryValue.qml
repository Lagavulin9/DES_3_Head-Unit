import QtQuick 2.15

Item {
    width: parent.width
    height: parent.height * 2 / 3

    property string currentUnit: "W"
    property double voltage: 0.0
    property double current: 0.0
    property double powerConsumption: 0.0

    property real currentValue: {
        if (currentUnit === "W") {
            return instrumentCluster.powerConsumption;
        } else if (currentUnit === "V") {
            return instrumentCluster.voltage;
        } else if (currentUnit === "mA") {
            return instrumentCluster.current;
        }
        return 0;
    }

    function switchUnit() {
        if (currentUnit === "W") {
            currentUnit = "V";
        } else if (currentUnit === "V") {
            currentUnit = "mA";
        } else if (currentUnit === "mA") {
            currentUnit = "W";
        }
    }

    function updateDisplay() {
        mainValue.text = currentValue.toString();
        secondaryText1.text = currentUnit === "W" ? instrumentCluster.voltage.toString() : (currentUnit === "V" ? instrumentCluster.current.toString() : instrumentCluster.powerConsumption.toString());
        secondaryText2.text = currentUnit === "W" ? instrumentCluster.current.toString() : (currentUnit === "V" ? instrumentCluster.powerConsumption.toString() : instrumentCluster.voltage.toString());
    }

    Connections {
        target: instrumentCluster
        onPowerConsumptionChanged: updateDisplay();
        onVoltageChanged: updateDisplay();
        onCurrentChanged: updateDisplay();
    }

    Text {
        id: mainValue
        anchors { horizontalCenter: parent.horizontalCenter; top: parent.top; topMargin: 156 }
        font { family: "Kanit"; pixelSize: 96; bold: true }
        text: currentValue.toString()
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
        onClicked: {
            switchUnit();
            updateDisplay(); 
        }
    }

    Component.onCompleted: {
        switchUnit();
        updateDisplay(); 
    }
}

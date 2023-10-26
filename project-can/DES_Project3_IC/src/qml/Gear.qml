import QtQuick 2.15

Item {
    width: parent.width
    height: parent.height / 3

    property string gearState: "P"

    function isCurrentGear(gear) {
        return gearState === gear ? 1 : 0.5
    }

    Item {
        id: gearGroup
        width: 280  
        height: 70
        anchors.centerIn: parent

        Rectangle {
            id: gearP
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
            width: 70
            height: parent.height
            color: "transparent"
            border.color: "transparent"
            opacity: isCurrentGear("P")

            Text {
                anchors.centerIn: parent
                font { family: "Kanit"; pixelSize: 40; bold: true }
                text: "P"
                color: "black"
            }
        }

        Rectangle {
            id: gearR
            anchors.left: gearP.right
            anchors.verticalCenter: parent.verticalCenter
            width: 70
            height: parent.height
            color: "transparent"
            border.color: "transparent"
            opacity: isCurrentGear("R")

            Text {
                anchors.centerIn: parent
                font { family: "Kanit"; pixelSize: 40; bold: true }
                text: "R"
                color: "black"
            }
        }

        Rectangle {
            id: gearN
            anchors.left: gearR.right
            anchors.verticalCenter: parent.verticalCenter
            width: 70
            height: parent.height
            color: "transparent"
            border.color: "transparent"
            opacity: isCurrentGear("N")

            Text {
                anchors.centerIn: parent
                font { family: "Kanit"; pixelSize: 40; bold: true }
                text: "N"
                color: "black"
            }
        }

        Rectangle {
            id: gearD
            anchors.left: gearN.right
            anchors.verticalCenter: parent.verticalCenter
            width: 70
            height: parent.height
            color: "transparent"
            border.color: "transparent"
            opacity: isCurrentGear("D")

            Text {
                anchors.centerIn: parent
                font { family: "Kanit"; pixelSize: 40; bold: true }
                text: "D"
                color: "black"
            }
        }
    }
}

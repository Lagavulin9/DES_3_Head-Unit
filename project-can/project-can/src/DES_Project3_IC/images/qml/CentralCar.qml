// Gauge.qml

import QtQuick 2.0

Item {
    id: item1
    width: 300
    height: 300

    Image {
        id: mainCarImg
        source: "images/bg-mask.png"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenterOffset: 89
        anchors.horizontalCenterOffset: 5
        width: 300
        height: 200
        anchors.verticalCenter: parent.verticalCenter

        Image {
            id: mainCarHighlights
            x: -42
            y: -18
            width: 383
            height: 226
            source: "images/car-highlights.png"
        }

        Image {
            id: mainCarHighlightsSurrond
            source: "images/car-highlights.png"
            x: -255
            y: -218
            width: 809
            height: 538
        }

    }
}



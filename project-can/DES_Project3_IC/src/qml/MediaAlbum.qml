import QtQuick 2.15

Item {
    id: item1
    width: parent.width
    height: parent.height * 3 / 5

    Image {
        id: mainImage

        width: 130
        height: 130
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 30
        anchors.horizontalCenter: parent.horizontalCenter
        source: "/images/CharliePuth.png"  // Main album cover
    }

    Image {
        y: 167
        width: 86
        height: 111
        anchors.verticalCenter: mainImage.verticalCenter
        anchors.left: mainImage.right
        source: "/images/LPHalf.png"

    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.66}
}
##^##*/

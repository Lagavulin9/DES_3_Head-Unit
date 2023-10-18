import QtQuick 2.15

Item {
    width: parent.width
    height: parent.height / 5

    Text {
        anchors.centerIn: parent
        font { family: "Kanit"; pixelSize: 16 }
        text: "Lyrics here..."  // Update with the lyrics of the song
        color: "black"
    }
}

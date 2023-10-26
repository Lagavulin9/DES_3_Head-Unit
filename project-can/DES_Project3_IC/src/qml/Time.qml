import QtQuick 2.15

Item {
    width: parent.width
    height: parent.height

    property date currentTime: new Date()

    // Calculate the milliseconds remaining until the next minute
    property int initialDelay: 60000 - (currentTime.getSeconds() * 1000 + currentTime.getMilliseconds())

    Timer {
        id: initialTimer
        interval: initialDelay
        running: true
        repeat: false
        onTriggered: {
            currentTime = new Date()
            minuteTimer.start()
        }
    }

    Timer {
        id: minuteTimer
        interval: 60000  // 1 minute
        running: false
        repeat: true
        onTriggered: currentTime = new Date()
    }

    Text {
        anchors.centerIn: parent
        font { family: "Kanit"; pixelSize: 20; bold: true }
        text: Qt.formatDateTime(currentTime, "hh:mm")
        color: "black"
    }
}

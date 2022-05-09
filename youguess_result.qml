import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 6.2

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Guess!")

    Text {
        id: text2
        x: 271
        y: 101
        text: qsTr("show me the result")
        font.pixelSize: 12
    }

    Button {
        id: button1
        x: 277
        y: 187
        width: 87
        height: 24
        text: qsTr("Play Again!")
        font.pixelSize: 12
    }
}

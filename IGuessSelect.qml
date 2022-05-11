import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 6.2

import Guesser 1.0
import Guessee 1.0

Page {
    width: 640
    height: 480
    visible: false


    Text {
        id: text1
        x: 231
        y: 102
        text: qsTr("Select a number and don't tell me!")
        font.pixelSize: 12
    }

    Button {
        id: button
        x: 277
        y: 179
        width: 87
        height: 24
        text: qsTr("I am Ready!")
        font.pixelSize: 12
    }
}

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 6.2

import Guesser 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Guess!")

    Text {
        id: text1
        x: 277
        y: 99
        width: 87
        height: 24
        text: qsTr("Who Will Guess?")
        font.pixelSize: 12
    }

    Button {
        id: button
        x: 277
        y: 179
        width: 87
        height: 24
        text: qsTr("I will guess!")
        font.pixelSize: 12

        onClicked: {
            the_guesser.start("worked?")
        }
    }

    Button {
        id: button1
        x: 277
        y: 254
        width: 87
        height: 24
        text: qsTr("You will guess!")
        font.pixelSize: 12
    }

}

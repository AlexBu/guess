import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 6.2

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Guess!")

    Text {
        id: text1
        x: 78
        y: 73
        text: qsTr("Guesser or Guessee:")
        font.pixelSize: 12
    }

    Button {
        id: button
        x: 298
        y: 186
        text: qsTr("Start!")
    }

    Guesser {
        id: one_guesser
    }
}

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 6.2

Window {
    width: 640
    height: 480
    visible: false

    Text {
        id: textIsIt
        x: 231
        y: 102
        width: 49
        height: 16
        text: qsTr("Is it :")
        font.pixelSize: 12
    }
    Text {
        id: textGuesserPrompted
        x: 330
        y: 102
        width: 27
        height: 16
        font.pixelSize: 12
    }

    ComboBox {
        id: comboBoxValA
        x: 211
        y: 230
        width: 34
        height: 20
    }

    ComboBox {
        id: comboBoxValB
        x: 330
        y: 230
        width: 29
        height: 20
    }

    Button {
        id: buttonGuesserContinue
        x: 277
        y: 352
        width: 87
        height: 24
        text: qsTr("Continue!")
        font.pixelSize: 12
    }

    Text {
        id: textStaticA
        x: 265
        y: 234
        text: qsTr("A")
        font.pixelSize: 12
    }

    Text {
        id: textStaticB
        x: 377
        y: 234
        width: 28
        height: 16
        text: qsTr("B")
        font.pixelSize: 12
    }
}

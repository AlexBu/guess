import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 6.2

import Guesser 1.0
import Guessee 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Guess!")


    StackView {
        id: stack
        initialItem: modeSelect
        anchors.fill: parent
    }

    Item {
        property int currentIndex
        Page {
            id: modeSelect
            visible: parent.currentIndex === 0
            Text {
                id: textSelectRole
                x: 277
                y: 99
                width: 87
                height: 24
                text: qsTr("Who Will Guess?")
                font.pixelSize: 12
            }

            Button {
                id: buttonGuesserStart
                x: 277
                y: 179
                width: 87
                height: 24
                text: qsTr("I will guess!")
                font.pixelSize: 12

                onClicked: {
                    the_guesser.start("I'm the guesser!");
                    stack.push(iGuessSelect)
                }
            }

            Button {
                id: buttonGuesseeStart
                x: 277
                y: 254
                width: 87
                height: 24
                text: qsTr("You will guess!")
                font.pixelSize: 12

                onClicked: {
                    the_guessee.start("I'm the guessee!")
                    stack.push(youGuessOneRound)
                }
            }
        }
        Page {
            id: iGuessSelect
            visible: parent.currentIndex === 1
            Text {
                id: textGuesserPromptNumber
                x: 231
                y: 102
                text: qsTr("Select a number and don't tell me!")
                font.pixelSize: 12
            }

            Button {
                id: buttonGuesserReady
                x: 277
                y: 179
                width: 87
                height: 24
                text: qsTr("I am Ready!")
                font.pixelSize: 12
            }
        }
        Page {
            id: youGuessOneRound
            visible: parent.currentIndex === 2
            Text {
                id: textGuesseePromptNumber
                x: 231
                y: 106
                text: qsTr("Select a number and don't tell me!")
                font.pixelSize: 12
            }

            Button {
                id: buttonGuesseeReady
                x: 277
                y: 179
                width: 87
                height: 24
                text: qsTr("I am Ready!")
                font.pixelSize: 12
            }
        }
        Page {
            id: iGuessOneRound
            visible: parent.currentIndex === 3
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
        Page {
            id: iGuessResult
            visible: parent.currentIndex === 4
            Text {
                id: text12
                x: 271
                y: 93
                text: qsTr("show me the result")
                font.pixelSize: 12
            }

            Button {
                id: button11
                x: 277
                y: 179
                width: 87
                height: 24
                text: qsTr("Play Again!")
                font.pixelSize: 12
            }
        }
        Page {
            id: youGuessResult
            visible: parent.currentIndex === 5
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
    }
}


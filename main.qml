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
                onClicked: {
                    the_guesser.start("I'm the guesser!");
                    stack.push(iGuessOneRound)
                }
            }
        }
        Page {
            id: youGuessOneRound
            visible: parent.currentIndex === 2
            Text {
                id: textIsIt2
                x: 231
                y: 106
                text: qsTr("Is it:")
                font.pixelSize: 12
            }

            Text {
                id: text3
                x: 297
                y: 102
                text: qsTr("Text")
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
                text: the_guesser.current
                Connections {
                    target: the_guesser
                    onCurrentChanged: {
                        console.log("onCurrentChanged")
                    }
                }
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
                onClicked: {
                    the_guesser.guess("");
                    stack.push(iGuessResult)
                }
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
                onClicked: {
                    the_guesser.end("");
                    stack.pop();
                    stack.pop();
                    stack.pop();
                }
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


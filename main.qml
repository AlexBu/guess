import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 6.2

import Guesser 1.0
import Guessee 1.0

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Let's Guess!")


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
                y: 97
                width: 87
                height: 24
                text: qsTr("Who Will Guess?")
                font.pixelSize: 12
            }

            Button {
                id: buttonGuesserStart
                x: 277
                y: 203
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
                y: 256
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
                y: 120
                text: qsTr("Select a number and don't tell me!")
                font.pixelSize: 12
            }

            Button {
                id: buttonGuesserReady
                x: 277
                y: 228
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
            id: iGuessOneRound
            visible: parent.currentIndex === 2

            Text {
                id: textStaticRound
                x: 214
                y: 82
                text: "Round: "
                font.pixelSize: 24
            }
            Text {
                id: textRound
                x: 350
                y: 82
                width: 129
                height: 16
                text: the_guesser.round
                font.pixelSize: 24
                Connections {
                    target: the_guesser
                    function onRoundChanged() {
                        console.log("onRoundChanged")
                        textRound.text = the_guesser.round
                    }
                }
            }
            Text {
                id: textIsIt
                x: 214
                y: 145
                width: 49
                height: 16
                text: qsTr("Is it :")
                font.pixelSize: 24
            }
            Text {
                id: textGuesserPrompted
                x: 350
                y: 145
                width: 121
                height: 16
                font.pixelSize: 24
                text: the_guesser.current
                Connections {
                    target: the_guesser
                    function onCurrentChanged() {
                        console.log("onCurrentChanged")
                    }
                }
            }

            ComboBox {
                id: comboBoxValA
                x: 214
                y: 236
                width: 65
                height: 20
                textRole: "value"
                valueRole: "value"
                model: [
                    {value: 0, text: "0"},
                    {value: 1, text: "1"},
                    {value: 2, text: "2"},
                    {value: 3, text: "3"},
                    {value: 4, text: "4"}
                ]
                onCurrentIndexChanged: {
                    console.log("on current index A changed")
                    the_guesser.valueA = comboBoxValA.currentIndex;
                }

                Connections {
                    target: the_guesser
                    function onValueAChanged() {
                        console.log("onValueAChanged")
                        comboBoxValA.currentIndex = the_guesser.valueA
                    }
                }
            }

            ComboBox {
                id: comboBoxValB
                x: 214
                y: 274
                width: 65
                height: 20
                textRole: "value"
                valueRole: "value"
                currentIndex: the_guesser.valueB
                model: [
                    {value: 0, text: "0"},
                    {value: 1, text: "1"},
                    {value: 2, text: "2"},
                    {value: 3, text: "3"},
                    {value: 4, text: "4"}
                ]
                onCurrentIndexChanged: {
                    console.log("on current index B changed")
                    the_guesser.valueB = comboBoxValB.currentIndex;
                }
                Connections {
                    target: the_guesser
                    function onValueBChanged() {
                        console.log("onValueBChanged")
                        comboBoxValB.currentIndex = the_guesser.valueB
                    }
                }
            }

            Button {
                id: buttonGuesserContinue
                x: 277
                y: 364
                width: 87
                height: 24
                text: qsTr("Continue!")
                font.pixelSize: 12
                onClicked: {
                    if (the_guesser.guess() === true) {
                        stack.push(iGuessResult, {textResultText:the_guesser.result});
                    }
                }
            }

            Text {
                id: textStaticA
                x: 299
                y: 238
                width: 261
                height: 16
                text: qsTr("A      Both the number AND the position are right")
                font.pixelSize: 12
            }

            Text {
                id: textStaticB
                x: 299
                y: 276
                width: 215
                height: 16
                text: qsTr("B      Only the number is right")
                font.pixelSize: 12
            }
        }
        Page {
            id: iGuessResult
            visible: parent.currentIndex === 3
            property alias textResultText: textResult.text
            Text {
                id: textResult
                x: 180
                y: 104
                text: "Guess result"
                font.pixelSize: 18
            }

            Button {
                id: buttonAgain
                x: 277
                y: 228
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
            id: youGuessOneRound
            visible: parent.currentIndex === 4
            Text {
                id: textStaticIsIt2
                x: 55
                y: 81
                width: 90
                height: 16
                text: qsTr("Is it:")
                font.pixelSize: 24
            }

            ComboBox {
                id: comboBoxNum1
                x: 55
                y: 119
                textRole: "value"
                valueRole: "value"
                model: [
                    {value: 0, text: "0"},
                    {value: 1, text: "1"},
                    {value: 2, text: "2"},
                    {value: 3, text: "3"},
                    {value: 4, text: "4"},
                    {value: 5, text: "5"},
                    {value: 6, text: "6"},
                    {value: 7, text: "7"},
                    {value: 8, text: "8"},
                    {value: 9, text: "9"},
                ]
                onCurrentIndexChanged: {
                    console.log("on current index N1 changed")
                    the_guessee.valueN1 = comboBoxNum1.currentIndex;
                }

                Connections {
                    target: the_guessee
                    function onValueN1Changed() {
                        console.log("onValueN1Changed")
                        comboBoxNum1.currentIndex = the_guessee.valueN1
                    }
                }
            }

            ComboBox {
                id: comboBoxNum2
                x: 151
                y: 119
                textRole: "value"
                valueRole: "value"
                model: [
                    {value: 0, text: "0"},
                    {value: 1, text: "1"},
                    {value: 2, text: "2"},
                    {value: 3, text: "3"},
                    {value: 4, text: "4"},
                    {value: 5, text: "5"},
                    {value: 6, text: "6"},
                    {value: 7, text: "7"},
                    {value: 8, text: "8"},
                    {value: 9, text: "9"},
                ]
                onCurrentIndexChanged: {
                    console.log("on current index N2 changed")
                    the_guessee.valueN2 = comboBoxNum2.currentIndex;
                }

                Connections {
                    target: the_guessee
                    function onValueN2Changed() {
                        console.log("onValueN2Changed")
                        comboBoxNum2.currentIndex = the_guessee.valueN2
                    }
                }
            }

            ComboBox {
                id: comboBoxNum3
                x: 247
                y: 119
                textRole: "value"
                valueRole: "value"
                model: [
                    {value: 0, text: "0"},
                    {value: 1, text: "1"},
                    {value: 2, text: "2"},
                    {value: 3, text: "3"},
                    {value: 4, text: "4"},
                    {value: 5, text: "5"},
                    {value: 6, text: "6"},
                    {value: 7, text: "7"},
                    {value: 8, text: "8"},
                    {value: 9, text: "9"},
                ]
                onCurrentIndexChanged: {
                    console.log("on current index N3 changed")
                    the_guessee.valueN3 = comboBoxNum3.currentIndex;
                }

                Connections {
                    target: the_guessee
                    function onValueN3Changed() {
                        console.log("onValueN3Changed")
                        comboBoxNum3.currentIndex = the_guessee.valueN3
                    }
                }
            }

            ComboBox {
                id: comboBoxNum4
                x: 343
                y: 119
                textRole: "value"
                valueRole: "value"
                model: [
                    {value: 0, text: "0"},
                    {value: 1, text: "1"},
                    {value: 2, text: "2"},
                    {value: 3, text: "3"},
                    {value: 4, text: "4"},
                    {value: 5, text: "5"},
                    {value: 6, text: "6"},
                    {value: 7, text: "7"},
                    {value: 8, text: "8"},
                    {value: 9, text: "9"},
                ]
                onCurrentIndexChanged: {
                    console.log("on current index N4 changed")
                    the_guessee.valueN4 = comboBoxNum4.currentIndex;
                }

                Connections {
                    target: the_guessee
                    function onValueN4Changed() {
                        console.log("onValueN4Changed")
                        comboBoxNum4.currentIndex = the_guessee.valueN4
                    }
                }
            }

            Button {
                id: buttonGuesseeReady
                x: 470
                y: 117
                width: 87
                height: 24
                text: qsTr("Guess")
                font.pixelSize: 12
                onClicked: {
                    if (the_guessee.guess() === true) {
                        stack.push(youGuessResult);
                    }
                }
            }

            Rectangle {
                id: rectangle
                x: 55
                y: 176
                width: 502
                height: 282
                color: "#ffffff"
                border.width: 2

                Text {
                    id: textGuesseeResult
                    text: the_guessee.recordGuesseeText
                    anchors.fill: parent
                    font.pixelSize: 12
                    Connections {
                        target: the_guessee
                        function onRecordGuesseeTextChanged() {
                            console.log("onRecordGuesseeTextChanged")
                        }
                    }

                }
            }

        }
        Page {
            id: youGuessResult
            visible: parent.currentIndex === 5
            Text {
                id: textStaticGuesseeResult
                x: 180
                y: 104
                text: the_guessee.resultGuesseePage
                font.pixelSize: 18
                Connections {
                    target: the_guessee
                    function onResultGuesseePageChanged() {
                        console.log("onResultGuesseePageChanged")
                    }
                }
            }

            Button {
                id: buttonGuesseeAgain
                x: 277
                y: 228
                width: 87
                height: 24
                text: qsTr("Play Again!")
                font.pixelSize: 12
                onClicked: {
                    the_guessee.end("");
                    stack.pop();
                    stack.pop();
                }
            }
        }
    }
}


import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Utilities

Rectangle {
    x: parent.x
    y: parent.y + parent.height + 10
    width: 300
    height: 200
    radius: 10
    color: "#C3111111"
    border.width: 1
    border.color: "#FF777777"
    visible: false
    Connections {
        target: qmlMainGui
        function onCloseAllOpenMenu() {
            hide();
        }
    }
    property int elementWidth: this.width
    property int elementHeight: 30
    property color textColor: "#EE999999"
    ColumnLayout {
        x: 10
        y: 5
        Rectangle {
            Layout.alignment: Qt.AlignLeft
            Layout.preferredWidth: elementWidth
            Layout.preferredHeight: elementHeight
            color: "transparent"
            RowLayout {
                Text {
                    Layout.alignment: Qt.AlignRight
                    Layout.preferredWidth: 175
                    Layout.preferredHeight: 30
                    text: "Z Position"
                    color: textColor
                    font.pixelSize: 16
                }
                Item {
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredHeight: 30
                    Rectangle {
                        width: 50
                        height: 30
                        color: "transparent"
                        border.color: "#EE999999"
                        border.width: 1
                        TextInput {
                            x: 3
                            width: parent.width - 5
                            height: parent.height
                            color: "#EE999999"
                            font.pixelSize: 20
                            text: "0000" // Set later to variable (Resolve negative values)
                            inputMask: "0000;"
                        }
                    }
                    CustomButton {
                        x: 55
                        width: 40
                        height: 30
                        bText.text: "Ok"
                        bBackground.radius: 10
                    }
                }
            }
        }
        Rectangle {
            Layout.alignment: Qt.AlignLeft
            Layout.preferredWidth: elementWidth
            Layout.preferredHeight: elementHeight
            color: "transparent"
            RowLayout {
                Text {
                    Layout.alignment: Qt.AlignRight
                    Layout.preferredWidth: 175
                    Layout.preferredHeight: 30
                    text: "Grid spacing"
                    color: textColor
                    font.pixelSize: 16
                }
                Item {
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredHeight: 30
                    Rectangle {
                        width: 50
                        height: 30
                        color: "transparent"
                        border.color: "#EE999999"
                        border.width: 1
                        TextInput {
                            x: 3
                            width: parent.width - 5
                            height: parent.height
                            color: "#EE999999"
                            font.pixelSize: 20
                            text: "000" // Finish translation and set to variable
                            inputMask: "000;"
                        }
                    }
                    CustomButton {
                        x: 55
                        width: 40
                        height: 30
                        bText.text: "Ok"
                        bBackground.radius: 10
                    }
                }
            }
        }
        Rectangle {
            Layout.alignment: Qt.AlignLeft
            Layout.preferredWidth: elementWidth
            Layout.preferredHeight: elementHeight
            color: "transparent"
            RowLayout {
                Text {
                    Layout.alignment: Qt.AlignRight
                    Layout.preferredWidth: 175
                    Layout.preferredHeight: 30
                    text: "Grid lightness"
                    color: textColor
                    font.pixelSize: 16
                }
                Item {
                    Layout.alignment: Qt.AlignLeft
                    Layout.preferredHeight: 30
                    Rectangle {
                        width: 50
                        height: 30
                        color: "transparent"
                        border.color: "#EE999999"
                        border.width: 1
                        TextInput {
                            x: 3
                            width: parent.width - 5
                            height: parent.height
                            color: "#EE999999"
                            font.pixelSize: 20
                            text: "20" // Set later to variable
                            inputMask: "00"
                        }
                    }
                    CustomButton {
                        x: 55
                        width: 40
                        height: 30
                        bText.text: "Ok"
                        bBackground.radius: 10
                    }
                }
            }
        }
    }

    function hide(){
        this.visible = false;
    }
}

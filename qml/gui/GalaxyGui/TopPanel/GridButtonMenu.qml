import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Utilities

Rectangle {
    id: gridButtonMenu
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
        function onCloseAllTabs() {
            hide();
            qmlMainWindow.switchFocus();
        }
    }
    property int elementWidth: this.width
    property int elementHeight: 30
    property color textColor: "#EE999999"
    ColumnLayout {
        x: 10
        y: 5
        Rectangle {
            id: zGalaxyGridPos
            Layout.alignment: Qt.AlignLeft
            Layout.preferredWidth: elementWidth
            Layout.preferredHeight: elementHeight
            color: "transparent"
            RowLayout {
                CustomButton {
                    Layout.alignment: Qt.AlignRight
                    Layout.preferredWidth: 175
                    Layout.preferredHeight: 30
                    bBackground.visible: false
                    bText.text: "Z Position"
                    bHoverHighlight: false
                    bBorder: false
                    bDesc: "Grid position in Z axis."
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
                            id: test1
                            x: 3
                            width: parent.width - 5
                            height: parent.height
                            color: "#EE999999"
                            font.pixelSize: 20
                            // Set later to variable (Resolve negative values)
                            text: C_Settings.getValue("zGalaxyGridPos", "int") ?? "0000"
                            inputMask: "####;"
                            onTextChanged:
                            {
                                qmlMainMap.zGalaxyGridPos = this.text * 1;
                                C_Settings.saveValue("zGalaxyGridPos", this.text, "int")
                            }
                        }
                    }
                }
            }
        }
        Rectangle {
            id: galaxyGridLines
            Layout.alignment: Qt.AlignLeft
            Layout.preferredWidth: elementWidth
            Layout.preferredHeight: elementHeight
            color: "transparent"
            RowLayout {
                CustomButton {
                    Layout.alignment: Qt.AlignRight
                    Layout.preferredWidth: 175
                    Layout.preferredHeight: 30
                    bBackground.visible: false
                    bText.text: "Grid Lines"
                    bHoverHighlight: false
                    bBorder: false
                    bDesc: "Amount of grid lines, more = smaller space between them."
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
                            // Set later to variable (Resolve negative values)
                            text: C_Settings.getValue("galaxyGridLines", "int") ?? "000"
                            inputMask: "###;"
                            onTextChanged:
                            {
                                C_Settings.saveValue("galaxyGridLines", this.text, "int")
                            }
                        }
                    }
                }
            }
        }
    }

    function hide(){
        this.visible = false;
    }
}

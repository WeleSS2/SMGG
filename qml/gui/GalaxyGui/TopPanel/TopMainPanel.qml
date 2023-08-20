import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Utilities

Item {
    x: qmlMainWindow.scheight_1 * 8
    width: qmlMainWindow.scwidth_1 * 20
    height: 60

    property int buttonHeight: 40
    property int buttonWidth: 40
    Rectangle {
        anchors.fill: parent
        radius: 10
        color: "#C3111111"
        border.width: 1
        border.color: "#FF777777"
        RowLayout {
            Layout.maximumWidth: parent.width
            spacing: 10
            x: 10
            y: 10
            CustomButton {
                id: qmlGridButton
                Layout.preferredHeight: buttonHeight
                Layout.preferredWidth: buttonWidth
                bImage.source: "gfx/grid.png"
                bBackground.visible: false
                MouseArea {
                    anchors.fill: parent
                    enabled: parent.enabled
                    acceptedButtons: Qt.LeftButton | Qt.RightButton
                    onClicked: function(mouse) {
                        if(mouse.button === Qt.LeftButton){
                            if(qmlMainMap.gridVisible){
                                qmlMainMap.gridVisible = false;
                            }
                            else
                                qmlMainMap.gridVisible = true;
                        }
                        else if (mouse.button === Qt.RightButton){
                            if(qmlGridButtonMenu.visible){
                                qmlMainGui.closeAllTabs();
                            }
                            else
                                qmlGridButtonMenu.visible = true;
                        }
                    }
                }
                GridButtonMenu {
                    id: qmlGridButtonMenu
                }
                bDesc: qmlGridButtonMenu.visible ? "" : "Left click to disable/enable grid
Right click to open/close options"
            }
            CustomButton {
                id: qmlSet90Button
                Layout.preferredHeight: buttonHeight
                Layout.preferredWidth: buttonWidth
                bImage.source: "gfx/set75.png"
                bBackground.visible: false
                MouseArea {
                    anchors.fill: parent
                    enabled: parent.enabled
                    onClicked: function(mouse) {
                        qmlMainMap.cameraAngleX = -75;
                    }
                }
                bDesc: "Set camera horizontally to default"
            }
            CustomButton {
                id: qmlSet0Button
                Layout.preferredHeight: buttonHeight
                Layout.preferredWidth: buttonWidth
                bImage.source: "gfx/set0.png"
                bBackground.visible: false
                MouseArea {
                    anchors.fill: parent
                    enabled: parent.enabled
                    onClicked: function(mouse) {
                        qmlMainMap.cameraAngleY = 0;
                    }
                }
                bDesc: "Set camera vertically to default"
            }
        }
    }
}

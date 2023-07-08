import QtQuick
import QtQuick.Controls

import WelcomeMenu
import DDDmap
import Gui

Window {
    property int scwidth_1: 0
    property int scheight_1: 0

    id: qmlMainWindow

    visibility: Window.FullScreen
    visible: true

    title: "SPS Tools"

    property color colorButtonBackground: "#D3060606"
    property color colorButtonBorder: "#FBDFDFDF"
    property color colorText: "#FBDFDFDF"
    WelcomeMenu {
        id: qmlWelcomeMenu
        visible: true
    }

    GalaxyMap {
        id: qmlMainMap
        visible: false
        enabled: false
    }

    SystemMap {
        id: qmlSystemMap
        visible: false
        enabled: false
    }

    GalaxyGui {
        id: qmlMainGui
        visible: false
        enabled: false
    }

    SystemGui {
        id: qmlSystemGui
        visible: false
        enabled: false
    }

    Button {
        id: qmlSettings
        property bool buttonIsHovered: false
        x: parent.width - 140
        y: parent.y
        width: 100
        height: 30
        background: Rectangle {
            color: "transparent"
            radius: 10
            Rectangle {
                radius: parent.radius
                anchors.fill: parent
                color: qmlMainWindow.colorButtonBackground
                border.width: 1
                border.color: qmlMainWindow.colorButtonBorder
            }
            Rectangle {
                radius: parent.radius
                anchors.fill: parent
                enabled: parent.enabled
                color: "#19FFFFFF"
                visible: parent.parent.buttonIsHovered
            }
            MouseArea {
                anchors.fill: parent
                enabled: parent.enabled
                hoverEnabled: true
                onEntered: {
                    parent.parent.buttonIsHovered = true;
                }
                onExited: {
                    parent.parent.buttonIsHovered = false;
                }
            }
        }
        indicator: Text {
            x: 11
            text: qsTr("Settings")
            color: qmlMainWindow.colorText
            font.bold: true
            font.pixelSize: 20
        }
        // onClicked:
    }

    Button {
        id: qmlExit
        property bool buttonIsHovered: false
        x: parent.width - 30
        y: parent.y
        width: 30
        height: 30
        background: Rectangle {
            color: "transparent"
            radius: 10
            Rectangle {
                radius: parent.radius
                anchors.fill: parent
                color: qmlMainWindow.colorButtonBackground
                border.width: 1
                border.color: qmlMainWindow.colorButtonBorder
            }
            Rectangle {
                radius: parent.radius
                anchors.fill: parent
                enabled: parent.enabled
                color: "#19FFFFFF"
                visible: parent.parent.buttonIsHovered
            }
            MouseArea {
                anchors.fill: parent
                enabled: parent.enabled
                hoverEnabled: true
                onEntered: {
                    parent.parent.buttonIsHovered = true;
                }
                onExited: {
                    parent.parent.buttonIsHovered = false;
                }
            }
        }
        indicator: Text {
            x: 8
            text: qsTr("X")
            color: qmlMainWindow.colorText
            font.bold: true
            font.pixelSize: 20
        }
        onClicked: Qt.quit()
    }

    Component.onCompleted: {
            scwidth_1 = qmlMainWindow.width / 100
            scheight_1 = qmlMainWindow.height / 100
        }
}

import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import QtMultimedia

Item {
    anchors.fill: parent
    MediaPlayer {
        id: mediaplayer
        source: "background.mp4"
        videoOutput: videoOutput
        loops: 100
    }

    VideoOutput {
        id: videoOutput
        anchors.fill: parent
    }

    Button {
        id: qmlMultiGalaxyGenerator
        property bool buttonIsHovered: false

        x: parent.width / 2 - 500
        y: parent.height / 2 - 350
        width: 450
        height: 700
        background: Rectangle {
            color: "transparent"
            radius: 25
            Rectangle {
                anchors.fill: parent
                color: qmlMainWindow.colorButtonBackground
                radius: parent.radius
                border.width: 1
                border.color: qmlMainWindow.colorButtonBorder
            }
            Rectangle {
                anchors.fill: parent
                enabled: parent.enabled
                radius: parent.radius
                color: "#19FFFFFF"
                visible: parent.parent.buttonIsHovered
            }
            Image {
                x: 25
                y: 25
                width: 400
                height: 500
                source: "galaxy.png"
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
            x: 20
            y: 550
            text: qsTr("Stellaris MultiGalaxy Generator")
            color: qmlMainWindow.colorText
            font.bold: true
            font.pixelSize: 28
        }
        onClicked: {
            qmlWelcomeMenu.visible = false;
            qmlMainMap.visible = true;
            qmlMainGui.visible = true;
            qmlMainMap.enabled = true;
            qmlMainGui.enabled = true;
            qmlMainMap.focus = true;
            console.log(qmlMainMap.enabled)
        }
    }
    Button {
        id: qmlModMaker
        property bool buttonIsHovered: false

        x: parent.width / 2 + 50
        y: parent.height / 2 - 350
        width: 450
        height: 700
        background: Rectangle {
            color: "transparent"
            radius: 25
            Rectangle {
                radius: parent.radius
                anchors.fill: parent
                color: qmlMainWindow.colorButtonBackground
                border.width: 1
                border.color: qmlMainWindow.colorButtonBorder
            }
            Rectangle {
                anchors.fill: parent
                enabled: parent.enabled
                radius: parent.radius
                color: "#19FFFFFF"
                visible: parent.parent.buttonIsHovered
            }
            Image {
                x: 25
                y: 25
                width: 400
                height: 500
                source: "galaxy.png"
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
            x: 50
            y: 550
            text: qsTr("Mods Maker (Unavailable)")
            color: qmlMainWindow.colorText
            font.bold: true
            font.pixelSize: 28
        }
    }

    Component.onCompleted: {
        mediaplayer.play();
    }
}

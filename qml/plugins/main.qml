import QtQuick
import QtQuick.Controls
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Button {
        x: 100
        y: 100
        width: 100
        height: 100
        background: Rectangle {
            color: "transparent"
            Image {
                anchors.fill: parent
                source: "discord.png"
            }
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: parent.color = "red"
                onExited: parent.color = "transparent"
            }
        }
    }
}

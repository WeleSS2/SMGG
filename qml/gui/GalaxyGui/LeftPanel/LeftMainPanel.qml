import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    y: qmlMainWindow.scheight_1 * 8
    width: 60
    height: qmlMainWindow.scheight_1 * 92

    property int buttonHeight: 40
    property int buttonWidth: 40
    Rectangle {
        anchors.fill: parent
        radius: 10
        color: "#C3111111"
        border.width: 1
        border.color: "#FF777777"
        ColumnLayout {
            Layout.maximumHeight: parent.height
            spacing: 10
            x: 10
            y: 10
            Button {
                Layout.preferredHeight: buttonHeight
                Layout.preferredWidth: buttonWidth
            }
            Button {
                Layout.preferredHeight: buttonHeight
                Layout.preferredWidth: buttonWidth
            }
            Button {
                Layout.preferredHeight: buttonHeight
                Layout.preferredWidth: buttonWidth
            }
            Button {
                Layout.preferredHeight: buttonHeight
                Layout.preferredWidth: buttonWidth
            }
        }
    }
}

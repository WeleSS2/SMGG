import QtQuick
import QtQuick.Controls

Item {
    Item {
        anchors.fill: parent
        enabled: parent.enabled
        ToolTip {
            visible: buttonIsHovered && bDesc !== ""
            contentItem: Text {
                text: bDesc
                font.pixelSize: 15
                font.bold: true
                color: mainTextColor
            }
            background: Rectangle {
                color: rectangleColor
                border.width: 1
                border.color: rectangleBorder
            }
        }
    }
}

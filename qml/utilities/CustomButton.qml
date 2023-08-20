import QtQuick
import QtQuick.Controls

Button {
    id: customButton
    property alias bBackground: customButtonBackground
    property alias bImage: customButtonImage
    property alias bText: customButtonText
    property bool bHover: true
    property bool bHoverHighlight: true
    property bool bBorder: true
    property int bBorderWidth: 1
    property string bDesc: ""

    property color rectangleColor: "#F1111111"
    property color rectangleBorder: "#FF777777"
    property color mainTextColor: "#EE999999"

    property bool buttonIsHovered: false

    background: Rectangle {
        color: "transparent"
        radius: customButtonBackground.radius
        Rectangle {
            id: customButtonBackground
            anchors.fill: parent
            color: rectangleColor
            border.width: bBorder === true ? bBorderWidth : 0
            border.color: rectangleBorder
        }
        Image {
            id: customButtonImage
            anchors.fill: parent
            visible: source !== ""
            source: ""
        }
        Rectangle {
            id: customButtonHover
            anchors.fill: parent
            enabled: parent.enabled
            color: "#2DFFFFFF"
            radius: customButtonBackground.radius
            visible: buttonIsHovered && bHoverHighlight
        }
        MouseArea {
            id: buttonHovered
            anchors.fill: parent
            enabled: parent.enabled
            hoverEnabled: true
            onEntered: {
                if(bHover){
                    buttonIsHovered = true;
                }
            }
            onExited: {
                if(bHover){
                    buttonIsHovered = false;
                }
            }
        }
        MouseArea {
            anchors.fill: parent
            enabled: !parent.enabled
            hoverEnabled: true
        }
    }
    indicator: Text {
        id: customButtonText
        anchors.centerIn: parent
        visible: text !== ""
        font.pixelSize: 16
        font.bold: true
        color: mainTextColor
        text: ""
    }
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


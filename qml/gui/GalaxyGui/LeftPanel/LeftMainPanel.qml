import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Utilities

Item {
    y: qmlMainWindow.scheight_1 * 8
    width: 60
    height: qmlMainWindow.scheight_1 * 92

    property int buttonHeight: 40
    property int buttonWidth: 40
    property int repeats: 0
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
            CustomButton {
                id: qmlSpawnGalaxyButton
                Layout.preferredHeight: buttonHeight
                Layout.preferredWidth: buttonWidth
                bBackground.visible: false
                bDesc: "Galaxy to spawn"
                MouseArea {
                    anchors.fill: parent
                    enabled: parent.enabled
                    acceptedButtons: Qt.LeftButton
                    onClicked: function(mouse) {
                        if(mouse.button === Qt.LeftButton)
                        {
                            repeats++;
                            qmlMainMap.addStar.append({posX: 0, posY: 0, posZ: (-500 * repeats)});
                            console.log("Spawn");
                            console.log("List size: ", qmlMainMap.addStar.count);
                        }
                    }
                }
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

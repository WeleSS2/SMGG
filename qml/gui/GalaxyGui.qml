import QtQuick
import "GalaxyGui/LeftPanel"
import "GalaxyGui/TopPanel"

import Utilities

Item {
    signal closeAllTabs()

    LeftMainPanel {
        id: qmlLeftMainPanel
        visible: true
    }
    CustomButton {
        y: qmlMainWindow.scheight_1 * 8 - 20
        width: 20
        height: 20
        bImage.source: "gfx/smallArrow.png"
        bBackground.visible: false
        MouseArea {
            anchors.fill: parent
            onClicked: function(mouse) {
                if(qmlLeftMainPanel.visible){
                    parent.bImage.visible = false;
                    qmlLeftMainPanel.visible = false;
                }
                else{
                    parent.bImage.visible = true;
                    qmlLeftMainPanel.visible = true;
                }
            }
        }
    }

    TopMainPanel {
        id: qmlTopMainPanel
        visible: true
    }
    CustomButton {
        x: qmlMainWindow.scheight_1 * 8 - 20
        width: 20
        height: 20
        bImage.source: "gfx/smallArrow.png"
        bImage.rotation: 90
        bBackground.visible: false
        MouseArea {
            anchors.fill: parent
            onClicked: function(mouse) {
                if(qmlTopMainPanel.visible){
                    parent.bImage.visible = false;
                    qmlTopMainPanel.visible = false;
                }
                else{
                    parent.bImage.visible = true;
                    qmlTopMainPanel.visible = true;
                }
            }
        }
    }
}

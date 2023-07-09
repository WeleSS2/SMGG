import QtQuick 2.15
import QtQuick3D
import QtQuick.Controls
import QtQuick.Window
import QtQuick3D.Helpers


Item {
    anchors.fill: parent
    focus: false
    property bool gridVisible: true
    property int zGalaxyGridPos: C_Settings.getValue("zGalaxyGridPos", "int") ?? -50
    property int cameraAngleX: -75
    property int cameraAngleY: 0

    property double camPosY: freeCamera.position.y / 25000;

    ListModel {
        id: starsModel
        ListElement {
            posX: 0
            posY: 0
            posZ: 0
        }

        ListElement {
            posX: 0
            posY: -50
            posZ: 0
        }

        ListElement {
            posX: 0
            posY: 50
            posZ: 0
        }

        ListElement {
            posX: 0
            posY: 0
            posZ: 80
        }

        ListElement {
            posX: 0
            posY: 0
            posZ: 100
        }

        ListElement {
            posX: 0
            posY: 0
            posZ: 2000
        }

        ListElement {
            posX: 0
            posY: 0
            posZ: 5000
        }
    }

    Component {
        id: starsDelegate
        Model {
            position: Qt.vector3d(posX, posY, posZ)
            scale: Qt.vector3d(0.1, 0.1, 0.1)
            source: "#Sphere"
            pickable: true

            materials: [ DefaultMaterial {
                    diffuseColor: "yellow"
                }
            ]
        }
    }

    View3D {
        id: view3D
        anchors.fill: parent

        environment: SceneEnvironment {
            antialiasingMode: SceneEnvironment.MSAA
            tonemapMode: SceneEnvironment.TonemapModeFilmic
            backgroundMode: SceneEnvironment.Color
            //lightProbe: Texture {
            //    source: "qrc:/gfx/background.hdr"
            //}
        }

        PerspectiveCamera {
            id: freeCamera
            position: Qt.vector3d(0, 2000, 300)
            clipFar: 15000
            eulerRotation: Qt.vector3d(cameraAngleX, cameraAngleY, 0)
        }

        DirectionalLight {
            brightness: 0.2
            color: Qt.rgba(1, 1, 1, 1.0)
            ambientColor: Qt.rgba(0.1, 0.1, 0.1, 1.0)
            eulerRotation.x: 90
        }

        DirectionalLight {
            brightness: 0.6
            color: Qt.rgba(1, 1, 1, 1.0)
            ambientColor: Qt.rgba(0.1, 0.1, 0.1, 1.0)
            eulerRotation.x: freeCamera.eulerRotation.x
        }

        Model {
            id: qmlGrid
            visible: gridVisible
            position: Qt.vector3d(0, zGalaxyGridPos, 0)
            scale: Qt.vector3d(2050, 2050, 0)
            eulerRotation.x: 90
            geometry: GridGeometry {
                horizontalLines: 50
                verticalLines: 50
            }
            materials: [ DefaultMaterial {
                    diffuseColor: "#FF333333"
                }
            ]
        }

        Repeater3D {
            model: starsModel
            delegate: starsDelegate
        }
    }

    Keys.onPressed: function(event) {
        if (event.key === Qt.Key_W) {
            cameraAngleX += 1;
        } else if (event.key === Qt.Key_S) {
            cameraAngleX -= 1;
        } else if (event.key === Qt.Key_A) {
            cameraAngleY += 1;
        } else if (event.key === Qt.Key_D) {
            cameraAngleY -= 1;
        }
    }
    property bool dragActive: false
    property point mousePos
    property point mousePosDrag
    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton | Qt.MiddleButton
        onWheel: function(mouse){
            qmlMainMap.focus = true;
            if(mouse.angleDelta.y > 0){
                if(freeCamera.position.y > 25)
                {
                    // Set current quarter to zoom while scrolling in this direction
                    var xMid = scwidth_1 * 50
                    var yMid = scheight_1 * 50

                    mousePos = this.mapToItem(view3D, mouse.x, mouse.y);

                    var angle = cameraAngleY * Math.PI / 180.0;

                    var cosAngle = Math.cos(angle);
                    var sinAngle = Math.sin(-angle);

                    var dragX = (xMid - mousePos.x) * (freeCamera.position.y / 7500);
                    var dragZ = (yMid - mousePos.y) * (freeCamera.position.y / 7500);

                    freeCamera.position.x -= (cosAngle * dragX - sinAngle * dragZ);
                    freeCamera.position.z -= (sinAngle * dragX + cosAngle * dragZ);

                    // Zoom
                    if(freeCamera.position.y > 1500){
                        freeCamera.position.y -= 250;
                    }
                    else if (freeCamera.position.y > 150)
                    {
                        freeCamera.position.y -= 75;
                    }
                    else
                        freeCamera.position.y -= 20;
                }
            }
            else
            {
                if(freeCamera.position.y < 6500)
                {
                    if(freeCamera.position.y > 1500){
                        freeCamera.position.y += 250;
                    }
                    else
                        freeCamera.position.y += 75;
                }
            }
            camPosY = freeCamera.position.y / 25000;
        }
        onPressed: function(mouse){
            if(mouse.button === Qt.LeftButton){
                mousePos = this.mapToItem(view3D, mouse.x, mouse.y);
                dragActive = true;
            }
            else if(mouse.button === Qt.RightButton){
                console.log("Right");
                var picked = view3D.pick(mouseX, mouseY);
                console.log(picked.objectHit);
                console.log(picked.position);
                console.log(picked.sceneNormal);
                console.log(picked.scenePosition);
                console.log(picked.uvPosition)
            }
        }
        onMouseXChanged: function(mouse){
            if(dragActive)
            {
                mousePosDrag = this.mapToItem(view3D, mouse.x, mouse.y);

                var angle = cameraAngleY * Math.PI / 180.0;

                var cosAngle = Math.cos(angle);
                var sinAngle = Math.sin(-angle);

                var dragX = (mousePosDrag.x - mousePos.x) * (camPosY);
                var dragZ = (mousePosDrag.y - mousePos.y) * (camPosY);

                freeCamera.position.x -= (cosAngle * dragX - sinAngle * dragZ);
                freeCamera.position.z -= (sinAngle * dragX + cosAngle * dragZ);
            }
        }
        onReleased: function(mouse){
            dragActive = false;
            mousePos = Qt.point(0,0);
        }
    }
}

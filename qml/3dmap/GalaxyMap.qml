import QtQuick 2.15
import QtQuick3D
import QtQuick.Controls
import QtQuick.Window
import QtQuick3D.Helpers
import Qt3D.Core
//import Qt3D.Render
import Qt3D.Extras

import "models"

Item {
    anchors.fill: parent
    focus: false
    property bool gridVisible: true
    property int zGalaxyGridPos: C_Settings.getValue("zGalaxyGridPos", "int") ?? -50
    property int gridValue: C_Settings.getValue("galaxyGridLines", "int") ?? 50
    property double gridStep: ((1000 / gridValue) / 9.75)
    property int test: 0

    property double cameraAngleX: -45
    property double cameraAngleY: 0

    property double camPosY: freeCamera.position.y / 25000;

    property alias addStar: modell1

    ListModel {
        id: modell1
        ListElement {
            posX: 0
            posY: 110
            posZ: 0
        }
        ListElement {
            posX: 0
            posY: 220
            posZ: 0
        }
    }

    ListModel {
        id: galaxies
        ListElement {
            _id: 1
        }
        ListElement {
            _id: 2
        }
        ListElement {
            _id: 3
        }
    }

    ListModel {
        id: stars
        ListElement {
            posX: 550
            posY: 160
            posZ: 0
        }
        ListElement {
            posX: 550
            posY: 260
            posZ: 0
        }
        ListElement {
            posX: 550
            posY: 360
            posZ: 0
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
            position: Qt.vector3d(0, 2000, 5000)
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
            brightness: 0.7
            color: Qt.rgba(1, 1, 1, 1.0)
            ambientColor: Qt.rgba(0.1, 0.1, 0.1, 1.0)
            eulerRotation: Qt.vector3d(cameraAngleX, cameraAngleY, 0)
        }
        Model {
            id: qmlGrid
            visible: gridVisible
            position: Qt.vector3d(0, zGalaxyGridPos, 0)
            scale: Qt.vector3d(100, 100, 0)
            eulerRotation.x: 90
            geometry: GridGeometry {
                horizontalLines: (gridValue + 1) ?? 50
                horizontalStep: gridStep
                verticalLines: (gridValue + 1) ?? 50
                verticalStep: gridStep
            }
            materials: [ DefaultMaterial {
                    diffuseColor: "#FF333333"
                }
            ]
        }

        Repeater3D {
            model: modell1
            delegate: starsDelegate
        }

        Repeater3D {
            id: galaxiesRepeater
            model: galaxies
            delegate: Component {
                id: galaxiesDelegate
                Model {
                    id: modelTest
                    required property int _id
                    Repeater3D {
                        model: stars
                        delegate: Component {
                            Model {
                                id: innerModel
                                property int galaxyId: modelTest._id

                                position: Qt.vector3d(galaxyId * posX, posY, posZ)
                                scale: Qt.vector3d(0.1, 0.1, 0.1)
                                source: "#Sphere"
                                pickable: true

                                materials: [ DefaultMaterial {
                                        diffuseColor: "green"
                                    }
                                ]
                            }
                        }
                    }
                }
            }
        }
    }

    Keys.onPressed: function(event) {
        if (event.key === Qt.Key_A)
        {
            cameraAngleY++;
        }
        if (event.key === Qt.Key_D)
        {
            cameraAngleY--;
        }
        if (event.key === Qt.Key_W)
        {
            cameraAngleX++;
        }
        if (event.key === Qt.Key_S)
        {
            cameraAngleX--;
        }
    }

    property bool dragActive: false
    property int count: 0
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

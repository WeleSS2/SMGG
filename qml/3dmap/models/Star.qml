import QtQuick 2.15
import QtQuick3D

Node {
    id: starbp
    Model {
        position: Qt.vector3d(0, 0, -100)
        scale: Qt.vector3d(0.5, 0.5, 0.5)
        source: "#Sphere"
        materials: [ PrincipledMaterial { baseColor: "green"; } ]
    }
}

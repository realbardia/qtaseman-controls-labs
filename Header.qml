import QtQuick 2.0
import AsemanQml.Test.Controls.Core 3.0

Scene {
    id: dis
    stylePath: "styles/simple/HeaderStyle.qml"

    property alias scene: scene
    default property alias items: scene.data

    Item {
        id: scene
        anchors.fill: parent
        anchors.topMargin: dis.styleItem.padding.top
        anchors.bottomMargin: dis.styleItem.padding.bottom
        anchors.leftMargin: dis.styleItem.padding.left
        anchors.rightMargin: dis.styleItem.padding.right
    }
}

import QtQuick 2.0
import AsemanQml.Test.Controls.Core 3.0

Control {
    id: dis
    styleFileName: "ItemDelegateStyle.qml"
    data: [marea, scene]

    property alias scene: scene
    default property alias items: scene.data

    property real radius: 8

    property alias pressedX: marea.mouseX
    property alias pressedY: marea.mouseY
    property alias pressed: marea.pressed
    property alias hovered: marea.containsMouse

    signal clicked()

    Keys.onReturnPressed: dis.clicked()
    Keys.onEnterPressed: dis.clicked()
    Keys.onSpacePressed: dis.clicked()

    MouseArea {
        id: marea
        hoverEnabled: true
        anchors.fill: parent
        onPressed: {
            dis.focus = true;
            dis.forceActiveFocus();
        }
        onClicked: dis.clicked()
    }

    Item {
        id: scene
        anchors.fill: parent
        anchors.topMargin: dis.styleItem.padding.top
        anchors.bottomMargin: dis.styleItem.padding.bottom
        anchors.leftMargin: dis.styleItem.padding.left
        anchors.rightMargin: dis.styleItem.padding.right
    }
}

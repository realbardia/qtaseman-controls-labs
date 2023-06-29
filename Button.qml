import QtQuick 2.0
import AsemanQml.Test.Controls.Core 3.0

Control {
    id: dis
    stylePath: "styles/simple/ButtonStyle.qml"

    property string text
    property string icon

    property real iconPixelSize: 14

    property bool highlighted
    property bool flat

    property real radius: 8

    property alias pressedX: marea.mouseX
    property alias pressedY: marea.mouseY
    property alias pressed: marea.pressed
    property alias hovered: marea.containsMouse

    signal clicked()

    MouseArea {
        id: marea
        hoverEnabled: true
        anchors.fill: parent
        onClicked: dis.clicked()
    }
}

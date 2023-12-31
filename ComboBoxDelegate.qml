import QtQuick 2.0
import AsemanQml.Test.Controls 3.0
import AsemanQml.Test.Controls.Core 3.0

Control {
    id: dis
    styleFileName: "ComboBoxDelegateStyle.qml"

    property string text
    property bool selected

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
}

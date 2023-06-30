import QtQuick 2.0
import AsemanQml.Test.Controls.Core 3.0

Control {
    id: dis
    stylePath: "styles/simple/CheckBoxStyle.qml"

    property string text
    property bool checked

    property alias pressedX: marea.mouseX
    property alias pressedY: marea.mouseY
    property alias pressed: marea.pressed
    property alias hovered: marea.containsMouse

    signal clicked()
    signal toggled()

    Keys.onSpacePressed: toggle()
    Keys.onReturnPressed: toggle()
    Keys.onEnterPressed: toggle()

    function toggle() {
        dis.checked = !dis.checked;
        toggled();
    }

    MouseArea {
        id: marea
        hoverEnabled: true
        anchors.fill: parent
        onPressed: {
            dis.focus = true;
            dis.forceActiveFocus();
        }
        onClicked: {
            toggle();
            dis.clicked();
        }
    }
}

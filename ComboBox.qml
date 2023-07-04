import QtQuick 2.0
import AsemanQml.Test.Controls 3.0
import AsemanQml.Test.Controls.Core 3.0

Control {
    id: dis
    styleFileName: "ComboBoxStyle.qml"

    property string textRole
    property string displayText: currentText
    readonly property string currentText: prv.currentText
    readonly property int currentIndex: prv.currentIndex
    property int count: 0

    property bool flat

    property real radius: 8

    property alias pressedX: marea.mouseX
    property alias pressedY: marea.mouseY
    property alias pressed: marea.pressed
    property alias hovered: marea.containsMouse

    Keys.onReturnPressed: dis.clicked()
    Keys.onEnterPressed: dis.clicked()
    Keys.onSpacePressed: dis.clicked()

    QtObject {
        id: prv
        property string currentText
        property int currentIndex
    }

    MouseArea {
        id: marea
        hoverEnabled: true
        anchors.fill: parent
        onPressed: {
            dis.focus = true;
            dis.forceActiveFocus();
        }
        onClicked: popup.open()
    }

    MenuPopup {
        id: popup
        width: dis.width
        height: 200
        transformOrigin: Item.Top
        styleFileName: "ComboBoxPopupStyle.qml"

        Item {
        }
    }
}

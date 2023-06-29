import QtQuick 2.15
import QtQuick.Window 2.15
import AsemanQml.Test.Controls 3.0
import AsemanQml.MaterialIcons 2.0

Window {
    id: win
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    MouseArea {
        anchors.fill: parent
        onClicked: console.debug(":)")
    }

    Page {
        anchors.fill: parent
        title: "Test"

        Button {
            id: btn
            anchors.centerIn: parent
            highlighted: true
            icon: MaterialIcons.mdi_dialpad
            text: "Test"
            onClicked: win.Style.highlightColor = "#0d80ec"
        }
    }
}

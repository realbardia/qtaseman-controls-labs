import QtQuick 2.0
import AsemanQml.Test.Controls 3.0

AbstractStyle {
    id: dis

    Rectangle {
        anchors.fill: parent
        color: control.Style.primaryColor
    }

    Rectangle {
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        color: control.Style.foregroundColor
        height: 1
        opacity: 0.2
    }
}

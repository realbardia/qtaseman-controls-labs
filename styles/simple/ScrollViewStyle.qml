import QtQuick 2.0
import AsemanQml.Test.Controls 3.0
import "../.." as Root

AbstractStyle {
    id: dis

    Root.ScrollBar {
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        z: 1000
        flickArea: control.flickArea
    }
}

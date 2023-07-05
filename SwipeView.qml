import QtQuick 2.15
import AsemanQml.Test.Controls.Core 3.0

Scene {
    id: dis
    styleFileName: "SwipeViewStyle.qml"
    data: [listv, sceneItem]

    default property alias list: sceneItem.data
    property int currentIndex
    property bool interactive: true

    Item {
        id: sceneItem
        anchors.fill: parent
    }
}

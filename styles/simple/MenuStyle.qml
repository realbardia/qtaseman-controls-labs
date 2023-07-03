import QtQuick 2.0
import AsemanQml.Test.Controls 3.0

MenuPopupStyle {
    id: dis

    Rectangle {
        parent: dis.foregroundScene
        anchors.fill: dis.foregroundItem
        color: dis.Style.baseColor
        radius: 8
    }
}

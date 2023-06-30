import QtQuick 2.0
import AsemanQml.Test.Controls 3.0
import AsemanQml.Test.Controls.Core 3.0

Scene {
    id: dis
    data: {
        var res = new Array;
        if (header) res[res.length] = header;
        if (footer) res[res.length] = footer;
        return res;
    }
    stylePath: "styles/simple/PageStyle.qml"

    Style.highlightColor: Palette.highlight
    Style.highlightTextColor: Palette.highlightText
    Style.foregroundColor: Palette.foreground
    Style.backgroundColor: Palette.background

    property string title
    property Item header
    property Item footer

    property alias scene: scene
    default property alias items: scene.data

    onHeaderChanged: {
        if (header) {
            header.parent = dis;
            header.anchors.left = left;
            header.anchors.right = right;
            header.anchors.top = top;
            header.z = 10;
        }
    }
    onFooterChanged: {
        if (footer) {
            footer.parent = dis;
            footer.anchors.left = left;
            footer.anchors.right = right;
            footer.anchors.bottom = bottom;
            footer.z = 10;
        }
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

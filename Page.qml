import QtQuick 2.0
import AsemanQml.Test.Controls 3.0
import AsemanQml.Test.Controls.Core 3.0

Scene {
    id: dis
    data: {
        var res = new Array;
        res[res.length] = background;
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

    default property alias items: scene.data

    onHeaderChanged: {
        if (header) {
            header.parent = dis;
            header.anchors.left = left;
            header.anchors.right = right;
            header.anchors.top = top;
        }
    }
    onFooterChanged: {
        if (footer) {
            footer.parent = dis;
            footer.anchors.left = left;
            footer.anchors.right = right;
            footer.anchors.bottom = bottom;
        }
    }

    Item {
        id: scene
        anchors.top: dis.header? dis.header.bottom : parent.top
        anchors.bottom: dis.footer? dis.footer.top : parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
    }
}

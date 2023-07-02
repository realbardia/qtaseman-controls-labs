import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0

AsemanObject {
    default property Component delegate

    property url stylePath: "styles/simple/FloatPageStyle.qml"
    property bool opened
    readonly property Item item: prv.item

    onOpenedChanged: {
        if (prv.item)
            prv.item.ViewportType.open = false;
        if (!opened)
            return;

        prv.item = Viewport.viewport.append(delegate, {}, stylePath)
    }

    onStylePathChanged: {
        if (opened) {
            close();
            open();
        }
    }

    QtObject {
        id: prv

        property Item item

        onItemChanged: if (!item) opened = false
    }

    function open() {
        opened = true;
    }
    function close() {
        opened = false;
    }

    Component.onDestruction: close()
}

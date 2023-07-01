import QtQuick 2.15
import AsemanQml.Viewport 2.0

QtObject {
    default property Component delegate

    function open() {
        Viewport.viewport.append(delegate, {}, "dialog")
    }
}

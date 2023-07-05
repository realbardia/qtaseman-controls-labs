import QtQuick 2.9
import AsemanQml.Test.Controls 3.0
import AsemanQml.Test.Controls.Core 3.0

ScrollViewCore {
    id: dis
    styleFileName: "ScrollViewStyle.qml"
    focusableUsingKeyboard: false

    onFlickAreaChanged: {
        if (!flickArea)
            return;

        dis.data = [flickArea];
        flickArea.anchors.fill = dis;
    }
}

import QtQuick 2.9
import AsemanQml.Test.Controls 3.0
import AsemanQml.Test.Controls.Core 3.0

ScrollViewCore {
    id: dis
    styleFileName: "ScrollBarStyle.qml"
    focusableUsingKeyboard: false

    property Flickable flickArea
    property int orientation: Qt.Vertical
    property color color: dis.Style.foregroundColor
    property bool forceVisible: false
}

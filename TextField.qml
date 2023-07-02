import QtQuick 2.15
import AsemanQml.Test.Controls.Core 3.0
import AsemanQml.Test.Controls 3.0

TextInput {
    id: dis
    font: styledItem.styleItem.font
    leftPadding: styledItem.styleItem.padding.left
    rightPadding: styledItem.styleItem.padding.right
    topPadding: styledItem.styleItem.padding.top
    bottomPadding: styledItem.styleItem.padding.bottom
    clip: true
    height: styledItem.implicitHeight

    selectedTextColor: dis.Style.accentTextColor
    selectionColor: dis.Style.accentColor
    selectByMouse: true
    color: dis.Style.foregroundColor

    property string placeholderText
    signal contextMenuRequest(real x, real y)

    Keys.onTabPressed: {
        styledItem.focusNextItem()
    }

    Control {
        id: styledItem
        stylePath: "styles/simple/TextFieldStyle.qml"
        sourceItem: dis
        onFocusedInUsingKeyboardChanged: {
            dis.focus = true;
            dis.forceActiveFocus();
        }
    }
}
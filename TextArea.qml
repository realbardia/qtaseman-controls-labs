import QtQuick 2.15
import AsemanQml.Test.Controls.Core 3.0
import AsemanQml.Test.Controls 3.0

TextEdit {
    id: dis
    font: styledItem.styleItem.font
    leftPadding: styledItem.styleItem.padding.left
    rightPadding: styledItem.styleItem.padding.right
    topPadding: styledItem.styleItem.padding.top
    bottomPadding: styledItem.styleItem.padding.bottom
    clip: true
    height: Math.max(32, contentHeight + 18)

    selectedTextColor: dis.Style.accentTextColor
    selectionColor: dis.Style.accentColor
    selectByMouse: true
    color: dis.Style.foregroundColor

    property string placeholderText
    signal contextMenuRequest()

    Keys.onTabPressed: {
        styledItem.focusNextItem()
    }

    Control {
        id: styledItem
        stylePath: "styles/simple/TextAreaStyle.qml"
        sourceItem: dis
        onFocusedInUsingKeyboardChanged: {
            dis.focus = true;
            dis.forceActiveFocus();
        }
    }
}

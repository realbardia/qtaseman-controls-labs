import QtQuick 2.15
import AsemanQml.Test.Controls.Core 3.0

Text {
    id: dis
    font.family: styledItem.styleItem.font.family
    font.pixelSize: styledItem.styleItem.font.pixelSize
    leftPadding: styledItem.styleItem.padding.left
    rightPadding: styledItem.styleItem.padding.right
    topPadding: styledItem.styleItem.padding.top
    bottomPadding: styledItem.styleItem.padding.bottom
    lineHeight: styledItem.styleItem.extra.lineHeight
    lineHeightMode: styledItem.styleItem.extra.lineHeightMode

    StyledItem {
        id: styledItem
        stylePath: "styles/simple/IconStyle.qml"
        sourceItem: dis
    }
}

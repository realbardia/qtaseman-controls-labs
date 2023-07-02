import QtQuick 2.15
import AsemanQml.Test.Controls.Core 3.0

Text {
    id: dis
    font: styledItem.styleItem.font
    leftPadding: styledItem.styleItem.padding.left
    rightPadding: styledItem.styleItem.padding.right
    topPadding: styledItem.styleItem.padding.top
    bottomPadding: styledItem.styleItem.padding.bottom
    lineHeight: styledItem.styleItem.extra.lineHeight
    lineHeightMode: styledItem.styleItem.extra.lineHeightMode

    StyledItem {
        id: styledItem
        styleFileName: "LabelStyle.qml"
        sourceItem: dis
    }
}

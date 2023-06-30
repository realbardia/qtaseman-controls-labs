import QtQuick 2.0
import AsemanQml.Test.Controls 3.0
import "../.." as Root

AbstractStyle {
    id: dis
    implicitHeight: 44
    implicitWidth: contentRow.width + 40

    Rectangle {
        anchors.fill: parent
        color: control.flat? "transparent" : control.highlighted? control.Style.highlightColor : "transparent"
        radius: control.radius

        Rectangle {
            anchors.fill: parent
            opacity: (!control.flat && !control.highlighted? 0.2 : 0) + (control.pressed? 0.1 : 0)
            color: control.Style.foregroundColor
            radius: control.radius
        }
    }

    Row {
        id: contentRow
        anchors.centerIn: parent
        spacing: 4

        Root.Icon {
            color: mainText.color
            pixelSize: control.iconPixelSize
            text: control.icon
            visible: text.length
        }

        Root.Label {
            id: mainText
            color: control.highlighted? control.Style.highlightTextColor : control.Style.foregroundColor
            text: control.text
            visible: text.length
        }
    }
}

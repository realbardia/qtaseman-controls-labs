import QtQuick 2.0
import AsemanQml.Test.Controls 3.0
import AsemanQml.MaterialIcons 2.0

AbstractStyle {
    id: dis
    implicitHeight: textArea.height
    implicitWidth: textArea.width

    Text {
        id: textArea
        color: control.color
        text: control.text
        font.pixelSize: control.pixelSize
        font.family: MaterialIcons.family
    }
}

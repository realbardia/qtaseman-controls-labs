import QtQuick 2.0
import AsemanQml.Test.Controls.Core 3.0

Control {
    id: dis
    styleFileName: "ProgressBarStyle.qml"
    focusableUsingKeyboard: false

    property real from: 0
    property real to: 100
    property real value: 0
}

pragma Singleton

import QtQuick 2.0
import AsemanQml.Test.Controls.Core 3.0

QtObject {
    property color foreground: MainPalette.foreground
    property color background: MainPalette.background
    property color accent: MainPalette.highlight
    property color accentText: MainPalette.highlightText
    property color base: MainPalette.base
    property color baseText: MainPalette.baseText
}

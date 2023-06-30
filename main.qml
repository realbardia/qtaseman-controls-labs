import QtQuick 2.15
import QtQuick.Window 2.15
import AsemanQml.Test.Controls 3.0
import AsemanQml.MaterialIcons 2.0

Window {
    id: win
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    MouseArea {
        anchors.fill: parent
        onClicked: console.debug(":)")
    }

    Page {
        id: page
        anchors.fill: parent
        title: "Test"

        header: Header {
            height: 50
            width: parent.width
        }
        footer: Footer {
            height: 50
            width: parent.width
        }

        Column {
            anchors.centerIn: parent
            spacing: 10

            Switch {
                id: switchBtn
                text: "Test Switch"
            }

            CheckBox {
                id: check
                text: "Test check"
            }

            Button {
                id: btn
                highlighted: true
                icon: MaterialIcons.mdi_dialpad
                text: "Test"
                onClicked: page.Style.accentColor = "#0d80ec"
            }

            ItemDelegate {
                width: 200
                onClicked: page.Style.accentColor = "#a00"

                Label {
                    anchors.centerIn: parent
                    text: "It's test"
                }
            }

            TextField {
                width: 200
                placeholderText: "It's Field"
            }

            TextArea {
                width: 200
                placeholderText: "It's Area 2"
            }
        }
    }
}

import QtQuick 2.15
import QtQuick.Window 2.15
import AsemanQml.Test.Controls 3.0
import AsemanQml.MaterialIcons 2.0

Window {
    id: win
    width: 480
    height: 640
    visible: true
    title: qsTr("Hello World")

    Page {
        id: page
        anchors.fill: parent
        title: "Home"

        Style.primaryColor: "#3f51b5"
        Style.primaryTextColor: "#fff"

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

            ProgressBar {
                value: 30
                width: 200
            }

            Slider {
                value: 30
                width: 200
            }
        }
    }
}

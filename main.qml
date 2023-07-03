import QtQuick 2.15
import AsemanQml.Test.Controls 3.0
import AsemanQml.MaterialIcons 2.0

Window {
    id: win
    width: 380
    height: 640
    visible: true
    title: qsTr("Hello World")

    Style.primaryColor: "#3f51b5"
    Style.primaryTextColor: "#fff"

    Page {
        id: page
        anchors.fill: parent
        title: "Home"

        header: Header {
            width: parent.width
        }
        footer: Footer {
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
                onClicked: test_stack.open()
            }

            ItemDelegate {
                width: 200
                onClicked: test_dialog.open()

                Label {
                    anchors.centerIn: parent
                    text: "It's test"
                }
            }

            TextField {
                width: 200
                placeholderText: "It's Field"
                onContextMenuRequest: {
                    test_menu.x = x;
                    test_menu.y = y;
                    test_menu.open()
                }

                Menu {
                    id: test_menu
                    width: 180
                    height: 200
                    transformOrigin: Item.TopLeft

                    Rectangle {
                        anchors.fill: parent
                        radius: 12
                    }
                }
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

    Dialog {
        id: test_dialog
        width: 300
        height: 300
        Item {
        }
    }

    StackPage {
        id: test_stack
        Page {
            id: testStack
            header: Header {
                height: 50
                width: parent.width
            }

            Button {
                anchors.centerIn: parent
                highlighted: true
                icon: MaterialIcons.mdi_chevron_left
                text: "Back"
                onClicked: test_stack.close()
            }
        }
    }
}

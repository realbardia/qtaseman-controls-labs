import QtQuick 2.15
import AsemanQml.Test.Controls 3.0
import AsemanQml.MaterialIcons 2.0

Window {
    id: win
    width: 380
    height: 700
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

        TabBar {
            id: tabBar
            anchors.left: parent.left
            anchors.right: parent.right
            onCurrentIndexChanged: swipe.currentIndex = currentIndex

            TabButton {
                text: "Tab 1"
            }
            TabButton {
                text: "Tab 2"
            }
            TabButton {
                text: "Tab 3"
            }
        }

        SwipeView {
            id: swipe
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.top: tabBar.bottom
            anchors.bottom: parent.bottom
            onCurrentIndexChanged: tabBar.currentIndex = currentIndex

            Item {
                ColumnLayout {
                    anchors.centerIn: parent

                    Switch {
                        id: switchBtn
                        text: "Test Switch"
                    }

                    CheckBox {
                        id: check
                        text: "Test check"
                    }

                    RadioButtonGroup {
                        id: radioGroup
                    }

                    Repeater {
                        model: 3
                        RadioButton {
                            ButtonGroup.group: radioGroup
                            text: "Radio " + (model.index + 1)
                        }
                    }

                    RowLayout {

                        Button {
                            id: btn
                            highlighted: true
                            icon: MaterialIcons.mdi_dialpad
                            text: "Test"
                            onClicked: test_stack.open()
                        }
                        Button {
                            highlighted: true
                            icon: MaterialIcons.mdi_chevron_right
                            text: "Next"
                            onClicked: swipe.currentIndex++
                        }
                    }

                    ComboBox {
                        id: combo
                        width: 100
                        textRole: "text"
                        model: ListModel {
                            ListElement { text: "Test" }
                            ListElement { text: "Lorem" }
                            ListElement { text: "Ipsum" }
                            ListElement { text: "Hello" }
                        }

                        popup.width: 140
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
                        id: textField
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
                            transformOrigin: Item.TopLeft

                            MenuButton {
                                text: "Copy"
                                onClicked: textField.copy()
                            }
                            MenuButton {
                                text: "Cut"
                                onClicked: textField.cut()
                            }
                            MenuButton {
                                text: "Paste"
                                onClicked: textField.paste()
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

            Item {

            }
            Item {

            }
        }
    }

    Dialog {
        id: test_dialog
        width: 300
        height: 300
        Item {

            Button {
                anchors.centerIn: parent
                highlighted: true
                icon: MaterialIcons.mdi_window_close
                text: "Close"
                onClicked: test_dialog.close()
            }
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

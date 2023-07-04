import QtQuick 2.0
import AsemanQml.Test.Controls.Core 3.0

MenuPopup {
    id: dis
    height: mainColumn.height
    styleFileName: "MenuStyle.qml"
    delegate: Item {
        id: listv

        Component.onCompleted: {
            for (var i=0; i<mainColumn.data.length; i++) {
                var b = mainColumn.data[i];
                if (b.clicked) {
                    b.clicked.connect(dis.close);
                }
            }
        }
    }

    property variant model: new Array
    default property alias sceneData: mainColumn.data

    data: [
        Scene {
            parent: dis.item? dis.item : dis
            visible: dis.item? true : false
            width: mainColumn.width
            height: mainColumn.height

            Column {
                id: mainColumn
                width: dis.item? dis.item.width : 200

                Repeater {
                    model: dis.model
                    delegate: Item {
                        width: mainColumn.width
                        height: 46

                        ItemDelegate {
                            anchors.fill: parent
                            anchors.margins: 4
                            onClicked: dis.close()

                            Label {
                                anchors.centerIn: parent
                                text: "Test " + model.index
                            }
                        }
                    }
                }
            }
        }
    ]
}

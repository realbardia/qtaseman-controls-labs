import QtQuick 2.0

MenuPopup {
    id: dis
    height: item && item.contentHeight? item.contentHeight : 200
    styleFileName: "MenuStyle.qml"
    delegate: ListView {
        id: listv
        model: dis.model
        clip: true
        delegate: Item {
            width: listv.width
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

    property variant model: new Array
}

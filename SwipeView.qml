import QtQuick 2.15
import AsemanQml.Test.Controls 3.0
import AsemanQml.Test.Controls.Core 3.0

Scene {
    id: dis
    data: [listv, sceneItem]

    default property alias list: sceneItem.data
    property alias currentIndex: listv.currentIndex

    Item {
        id: sceneItem
        anchors.fill: parent
    }

    ListView {
        id: listv
        anchors.fill: parent
        orientation: ListView.Horizontal
        highlightRangeMode: ListView.StrictlyEnforceRange
        highlightMoveDuration: 200
        snapMode: ListView.SnapOneItem
        clip: true
        model: {
            var res = new Array;
            for (var i=0 ;i<list.length; i++) {
                var item = list[i];
                if (item.transformOrigin == undefined)
                    continue;

                res[res.length] = item;
            }
            return res;
        }
        delegate: Scene {
            id: item
            width: listv.width
            height: listv.height
            clip: true

            Component.onCompleted: {
                modelData.parent = item;
                modelData.anchors.fill = item;
            }
        }
    }
}

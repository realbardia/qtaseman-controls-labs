import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import AsemanQml.Test.Controls.Core 3.0

Item {
    id: dis

    property url stylePath: "styles/simple/MenuStyle.qml"

    default property Component delegate
    property bool opened
    readonly property Item item: prv.item

    onOpenedChanged: {
        if (prv.scene)
            prv.scene.ViewportType.open = false;
        if (!opened)
            return;

        prv.scene = Viewport.viewport.append(sceneItem, {}, stylePath)
    }

    onStylePathChanged: {
        if (opened) {
            close();
            open();
        }
    }

    QtObject {
        id: prv

        property Item item
        property Item scene

        onSceneChanged: if (!scene) opened = false
    }

    function open() {
        opened = true;
    }
    function close() {
        opened = false;
    }

    Component {
        id: sceneItem
        Scene {
            id: scene

            PointMapListener {
                id: mapListener
                source: dis.parent
                dest: Viewport.viewport
            }

            Component.onCompleted: {
                prv.item = delegate.createObject(scene);
                x = Qt.binding(function(){ return mapListener.result.x + dis.x; });
                y = Qt.binding(function(){ return mapListener.result.y + dis.y; });
                width = Qt.binding(function(){ return dis.width; });
                height = Qt.binding(function(){ return dis.height; });
                scene.ViewportType.transformOrigin = Qt.binding(function(){
                    switch (dis.transformOrigin) {
                    case Item.Left:
                        return Qt.point(0, dis.height/2);
                    default:
                    case Item.TopLeft:
                        return Qt.point(0, 0);
                    case Item.Top:
                        return Qt.point(dis.width/2, 0);
                    case Item.TopRight:
                        return Qt.point(dis.width, 0);
                    case Item.Right:
                        return Qt.point(dis.width, dis.height/2);
                    case Item.BottomRight:
                        return Qt.point(dis.width, dis.height);
                    case Item.Bottom:
                        return Qt.point(dis.width/2, dis.height);
                    case Item.BottomLeft:
                        return Qt.point(0, dis.height);
                    case Item.Center:
                        return Qt.point(dis.width/2, dis.height/2);
                    }
                });
            }
        }
    }
}
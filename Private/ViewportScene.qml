import QtQuick 2.15
import AsemanQml.Base 2.0
import AsemanQml.Viewport 2.0
import AsemanQml.Test.Controls.Core 3.0
import AsemanQml.Test.Controls 3.0

AsemanObject {
    id: dis

    property string styleFileName
    default property Component delegate

    readonly property Item item: prv.item

    property bool opened: false

    property real x
    property real y
    property real width
    property real height

    property real gestureWidth: -1
    property real maximumWidth: 0
    property int transformOrigin: Item.TopLeft
    property bool touchToClose: true
    property bool blockBack: false

    property int geometryMode: SnapToView

    enum GeometryMode {
        FreeGeometry,
        FreeSizeOnly,
        SnapToView
    }

    onOpenedChanged: {
        if (prv.scene)
            prv.scene.ViewportType.open = false;
        if (!opened)
            return;

        var cmp;
        switch (geometryMode) {
        case ViewportScene.FreeGeometry:
            cmp = freeSceneItem;
            break;
        case ViewportScene.FreeSizeOnly:
            cmp = freeSizeSceneItem;
            break;
        default:
        case ViewportScene.SnapToView:
            cmp = snappedSceneItem;
            break;
        }

        prv.scene = Viewport.viewport.append(cmp, {}, dis.Style.styleUrl + '/' + styleFileName)
    }

    onStyleFileNameChanged: {
        if (opened) {
            close();
            open();
        }
    }

    QtObject {
        id: prv

        property Item item
        property Item scene
        property point transformPoint: {
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
        }

        function setupViewportType(item) {
            item.ViewportType.transformOrigin = Qt.binding(function(){ return prv.transformPoint; });
            item.ViewportType.gestureWidth = Qt.binding(function(){ return dis.gestureWidth<0? item.width : dis.gestureWidth; });
            item.ViewportType.maximumWidth = Qt.binding(function(){ return dis.maximumWidth; });
            item.ViewportType.touchToClose = Qt.binding(function(){ return dis.touchToClose; });
            item.ViewportType.blockBack = Qt.binding(function(){ return dis.blockBack; });
        }

        onSceneChanged: if (!scene) opened = false
    }

    function open() {
        opened = true;
    }
    function close() {
        opened = false;
    }

    Component {
        id: snappedSceneItem
        Scene {
            id: scene

            Component.onCompleted: {
                prv.item = delegate.createObject(Viewport.viewport, {"parent": scene});
                prv.item.anchors.fill = scene;
                prv.setupViewportType(scene);
            }
            Component.onDestruction: {
                prv.item.destroy()
            }
        }
    }

    Component {
        id: freeSizeSceneItem
        Scene {
            id: scene

            Component.onCompleted: {
                prv.item = delegate.createObject(Viewport.viewport, {"parent": scene});
                prv.item.anchors.fill = scene;
                prv.setupViewportType(scene);
                width = Qt.binding(function(){ return dis.width; });
                height = Qt.binding(function(){ return dis.height; });
            }
            Component.onDestruction: {
                prv.item.destroy()
            }
        }
    }

    Component {
        id: freeSceneItem
        Scene {
            id: scene

            PointMapListener {
                id: mapListener
                source: dis.parent
                dest: Viewport.viewport
            }

            Component.onCompleted: {
                prv.item = delegate.createObject(Viewport.viewport, {"parent": scene});
                prv.item.anchors.fill = scene;
                prv.setupViewportType(scene);
                x = Qt.binding(function(){ return mapListener.result.x + dis.x; });
                y = Qt.binding(function(){ return mapListener.result.y + dis.y; });
                width = Qt.binding(function(){ return dis.width; });
                height = Qt.binding(function(){ return dis.height; });
            }
            Component.onDestruction: {
                prv.item.destroy()
            }
        }
    }
}

import QtQuick 2.0
import AsemanQml.Test.Controls.Core 3.0
import AsemanQml.Viewport 2.0

AbstractViewportScene {
    sceneComponent: snappedSceneItem

    Component {
        id: snappedSceneItem
        Scene {
            id: scene

            property variant prv

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
}

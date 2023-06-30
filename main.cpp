#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "asemanquicksceneitem.h"
#include "asemanquickcontrolitem.h"
#include "asemanquickmainpalette.h"
#include "asemanquickabstractbutton.h"
#include "asemanquickstyleattachedproperty.h"
#include "asemanquickabstractstyle.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    qmlRegisterType<AsemanQuickSceneItem>("AsemanQml.Test.Controls.Core", 3, 0, "Scene");
    qmlRegisterType<AsemanQuickControlItem>("AsemanQml.Test.Controls.Core", 3, 0, "Control");
    qmlRegisterType<AsemanQuickStyledItem>("AsemanQml.Test.Controls.Core", 3, 0, "StyledItem");
    qmlRegisterType<AsemanQuickAbstractStyle>("AsemanQml.Test.Controls", 3, 0, "AbstractStyle");
    qmlRegisterUncreatableType<AsemanQuickStyleProperty>("AsemanQml.Test.Controls", 3, 0, "Style", "");
    qmlRegisterUncreatableType<AsemanQuickBoxSize>("AsemanQml.Test.Controls", 3, 0, "BoxSize", "");
    qmlRegisterSingletonInstance<AsemanQuickMainPalette>("AsemanQml.Test.Controls.Core", 3, 0, "MainPalette", new AsemanQuickMainPalette);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

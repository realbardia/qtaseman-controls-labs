#include "asemanquickstyleditem.h"

#include <QQmlContext>
#include <QtQml>

AsemanQuickStyledItem::AsemanQuickStyledItem(QQuickItem *parent)
    : QQuickItem(parent)
{
    mStyleItem = new AsemanQuickAbstractStyle(this);

    connect(this, &AsemanQuickStyledItem::widthChanged, this, &AsemanQuickStyledItem::reposItems);
    connect(this, &AsemanQuickStyledItem::heightChanged, this, &AsemanQuickStyledItem::reposItems);
}

AsemanQuickStyledItem::~AsemanQuickStyledItem()
{
}

QQmlComponent *AsemanQuickStyledItem::styleComponent() const
{
    return mStyleComponent;
}

void AsemanQuickStyledItem::setStyleComponent(QQmlComponent *newStyleComponent)
{
    if (mStyleComponent == newStyleComponent)
        return;

    if (mStyleItem)
    {
        delete mStyleItem;
        mStyleItem = nullptr;
    }

    mStyleComponent = newStyleComponent;
    if (mStyleComponent && mStyleComponent->isReady())
    {
        auto context = qmlContext(this);
        auto newContext = new QQmlContext(context, this);
        newContext->setContextProperty("control", this);

        QVariantMap properties = {
            {"parent", QVariant::fromValue<QObject*>(this)}
        };

        auto obj = mStyleComponent->createWithInitialProperties(properties, newContext);
        mStyleItem = qobject_cast<typeof(mStyleItem)>(obj);
        if (mStyleItem)
        {
            connect(mStyleItem, &QQuickItem::implicitWidthChanged, this, &AsemanQuickStyledItem::reinitImplicitSizes);
            connect(mStyleItem, &QQuickItem::implicitHeightChanged, this, &AsemanQuickStyledItem::reinitImplicitSizes);
            reinitImplicitSizes();
        }
        else
            delete obj;
    }

    Q_EMIT styleItemChanged();
    Q_EMIT styleComponentChanged();
}

void AsemanQuickStyledItem::reposItems()
{
    if (mStyleItem)
    {
        mStyleItem->setX(0);
        mStyleItem->setY(0);
        mStyleItem->setWidth(width());
        mStyleItem->setHeight(height());
    }
}

void AsemanQuickStyledItem::reinitImplicitSizes()
{
    if (mStyleItem)
    {
        setImplicitWidth(mStyleItem->implicitWidth());
        setImplicitHeight(mStyleItem->implicitHeight());
    }
}

AsemanQuickAbstractStyle *AsemanQuickStyledItem::styleItem() const
{
    return mStyleItem;
}

QUrl AsemanQuickStyledItem::stylePath() const
{
    return mStylePath;
}

void AsemanQuickStyledItem::setStylePath(const QUrl &newStylePath)
{
    if (mStylePath == newStylePath)
        return;
    mStylePath = newStylePath;
    if (!mStylePath.isEmpty())
    {
        auto engine = qmlEngine(this);
        if (engine)
        {
            auto component = new QQmlComponent(engine, mStylePath, this);
            if (component->isError())
                qmlWarning(this) << component->errorString();
            else
                setStyleComponent(component);
        }
    }

    Q_EMIT stylePathChanged();
}

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

    mStyleComponent = newStyleComponent;
    setupStyleItem();
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

void AsemanQuickStyledItem::setupStyleItem()
{
    if (mStyleItem)
    {
        delete mStyleItem;
        mStyleItem = nullptr;
    }

    if (!mSourceItem)
        return;
    if (!mStyleComponent || !mStyleComponent->isReady())
        return;

    auto context = qmlContext(this);
    auto newContext = new QQmlContext(context, this);
    newContext->setContextProperty("control", mSourceItem);

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

    Q_EMIT styleItemChanged();
}

QQuickItem *AsemanQuickStyledItem::sourceItem() const
{
    return mSourceItem;
}

void AsemanQuickStyledItem::setSourceItem(QQuickItem *newSourceItem)
{
    if (mSourceItem == newSourceItem)
        return;
    mSourceItem = newSourceItem;
    setupStyleItem();
    Q_EMIT sourceItemChanged();
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
                qDebug() << component->errorString().toStdString().c_str();
            else
                setStyleComponent(component);
        }
    }

    Q_EMIT stylePathChanged();
}

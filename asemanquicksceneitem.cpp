#include "asemanquicksceneitem.h"

AsemanQuickSceneItem::AsemanQuickSceneItem(QQuickItem *parent)
    : AsemanQuickStyledItem(parent)
{
    setAcceptHoverEvents(true);
    setAcceptTouchEvents(true);
    setAcceptedMouseButtons(Qt::AllButtons);
}

AsemanQuickSceneItem::~AsemanQuickSceneItem()
{
}

QList<AsemanQuickControlItem *> AsemanQuickSceneItem::controls() const
{
    return AsemanQuickControlItem::findAllControls(this, true);
}

AsemanQuickSceneItem *AsemanQuickSceneItem::findScene(const QQuickItem *item)
{
    if (!item)
        return nullptr;

    auto parent = item->parentItem();
    while (parent)
    {
        auto obj = qobject_cast<AsemanQuickSceneItem*>(parent);
        if (obj)
            return obj;

        parent = parent->parentItem();
    }
    return nullptr;
}

void AsemanQuickSceneItem::mouseMoveEvent(QMouseEvent *e)
{
    e->accept();
}

void AsemanQuickSceneItem::mousePressEvent(QMouseEvent *e)
{
    e->accept();
}

void AsemanQuickSceneItem::mouseReleaseEvent(QMouseEvent *e)
{
    e->accept();
}

void AsemanQuickSceneItem::mouseUngrabEvent()
{
}

void AsemanQuickSceneItem::touchEvent(QTouchEvent *e)
{
    e->accept();
}

void AsemanQuickSceneItem::touchUngrabEvent()
{
}

void AsemanQuickSceneItem::wheelEvent(QWheelEvent *e)
{
    e->accept();
}

QFont AsemanQuickSceneItem::font() const
{
    return mFont;
}

void AsemanQuickSceneItem::setFont(const QFont &newFont)
{
    if (mFont == newFont)
        return;
    mFont = newFont;
    Q_EMIT fontChanged();
}

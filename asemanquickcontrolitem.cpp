#include "asemanquickcontrolitem.h"
#include "asemanquicksceneitem.h"

#include <QKeyEvent>

AsemanQuickControlItem::AsemanQuickControlItem(QQuickItem *parent)
    : AsemanQuickStyledItem(parent)
{
}

AsemanQuickControlItem::~AsemanQuickControlItem()
{
}

void AsemanQuickControlItem::focusNextItem()
{
    auto next = mNextTabOrder;
    if (!next)
    {
        const auto scene = AsemanQuickSceneItem::findScene(this);
        const auto controls = findAllControls(scene, true);
        const auto index = controls.indexOf(this);
        if (index >= 0 && index < controls.size()-1)
            next = controls.at(index+1);
    }

    if (next)
    {
        next->setFocus(true);
        next->forceActiveFocus();
    }
}

void AsemanQuickControlItem::focusPreviousItem()
{
    auto prev = mPreviousTabOrder;
    if (!prev)
    {
        const auto scene = AsemanQuickSceneItem::findScene(this);
        const auto controls = findAllControls(scene, true);
        const auto index = controls.indexOf(this);
        if (index > 0)
            prev = controls.at(index-1);
    }

    if (prev)
    {
        prev->setFocus(true);
        prev->forceActiveFocus();
    }

}

void AsemanQuickControlItem::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
    case Qt::Key_Tab:
        if (e->modifiers() & Qt::ShiftModifier)
            focusPreviousItem();
        else
            focusNextItem();
        break;

    default:
        QQuickItem::keyPressEvent(e);
        break;
    }

    e->accept();
}

AsemanQuickControlItem *AsemanQuickControlItem::nextTabOrder() const
{
    return mNextTabOrder;
}

void AsemanQuickControlItem::setNextTabOrder(AsemanQuickControlItem *newNextTabOrder)
{
    if (mNextTabOrder == newNextTabOrder)
        return;

    if (mNextTabOrder)
    {
        mNextTabOrder->mPreviousTabOrder = nullptr;
        Q_EMIT mNextTabOrder->nextTabOrderChanged();
    }

    mNextTabOrder = newNextTabOrder;
    if (mNextTabOrder)
    {
        mNextTabOrder->mPreviousTabOrder = this;
        Q_EMIT mNextTabOrder->nextTabOrderChanged();
    }

    Q_EMIT nextTabOrderChanged();
}

QList<AsemanQuickControlItem *> AsemanQuickControlItem::findAllControls(const QQuickItem *item, bool recursive)
{
    QList<AsemanQuickControlItem*> res;
    if (!item)
        return res;

    for (auto obj: item->childItems())
    {
        auto child = qobject_cast<AsemanQuickControlItem*>(obj);
        if (child)
            res << child;
        if (recursive)
            res << findAllControls(child, true);
    }

    return res;
}

#ifndef ASEMANQUICKCONTROLITEM_H
#define ASEMANQUICKCONTROLITEM_H

#include "asemanquickstyleditem.h"

class AsemanQuickControlItem : public AsemanQuickStyledItem
{
    Q_OBJECT
    Q_PROPERTY(AsemanQuickControlItem *nextTabOrder READ nextTabOrder WRITE setNextTabOrder NOTIFY nextTabOrderChanged)

public:
    AsemanQuickControlItem(QQuickItem *parent = nullptr);
    virtual ~AsemanQuickControlItem();

    static QList<AsemanQuickControlItem*> findAllControls(const QQuickItem *item, bool recursive = true);

    AsemanQuickControlItem *nextTabOrder() const;
    void setNextTabOrder(AsemanQuickControlItem *newNextTabOrder);

public Q_SLOTS:
    void focusNextItem();
    void focusPreviousItem();

Q_SIGNALS:
    void nextTabOrderChanged();

protected:
    void keyPressEvent(QKeyEvent *e) override;

private:
    QPointer<AsemanQuickControlItem> mNextTabOrder;
    QPointer<AsemanQuickControlItem> mPreviousTabOrder;
};

#endif // ASEMANQUICKCONTROLITEM_H

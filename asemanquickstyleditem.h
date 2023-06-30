#ifndef ASEMANQUICKSTYLEDITEM_H
#define ASEMANQUICKSTYLEDITEM_H

#include <QQuickItem>
#include <QQmlComponent>
#include <QPointer>
#include <QUrl>

#include "asemanquickabstractstyle.h"

class AsemanQuickStyledItem : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QQuickItem *sourceItem READ sourceItem WRITE setSourceItem NOTIFY sourceItemChanged)
    Q_PROPERTY(QQmlComponent *styleComponent READ styleComponent WRITE setStyleComponent NOTIFY styleComponentChanged)
    Q_PROPERTY(QUrl stylePath READ stylePath WRITE setStylePath NOTIFY stylePathChanged)
    Q_PROPERTY(AsemanQuickAbstractStyle *styleItem READ styleItem NOTIFY styleItemChanged)

public:
    AsemanQuickStyledItem(QQuickItem *parent = nullptr);
    virtual ~AsemanQuickStyledItem();

    QQmlComponent *styleComponent() const;
    void setStyleComponent(QQmlComponent *newStyleComponent);

    QUrl stylePath() const;
    void setStylePath(const QUrl &newStylePath);

    AsemanQuickAbstractStyle *styleItem() const;

    QQuickItem *sourceItem() const;
    void setSourceItem(QQuickItem *newSourceItem);

Q_SIGNALS:
    void styleComponentChanged();
    void stylePathChanged();
    void styleItemChanged();
    void sourceItemChanged();

protected:
    void reposItems();
    void reinitImplicitSizes();
    void setupStyleItem();

private:
    QPointer<QQuickItem> mSourceItem;
    QPointer<QQmlComponent> mStyleComponent;
    QUrl mStylePath;
    AsemanQuickAbstractStyle *mStyleItem = nullptr;
};

#endif // ASEMANQUICKSTYLEDITEM_H

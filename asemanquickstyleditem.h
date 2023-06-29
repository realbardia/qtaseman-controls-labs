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
    Q_PROPERTY(QQmlComponent *styleComponent READ styleComponent WRITE setStyleComponent NOTIFY styleComponentChanged)
    Q_PROPERTY(QUrl stylePath READ stylePath WRITE setStylePath NOTIFY stylePathChanged)

public:
    AsemanQuickStyledItem(QQuickItem *parent = nullptr);
    virtual ~AsemanQuickStyledItem();

    QQmlComponent *styleComponent() const;
    void setStyleComponent(QQmlComponent *newStyleComponent);

    QUrl stylePath() const;
    void setStylePath(const QUrl &newStylePath);

Q_SIGNALS:
    void styleComponentChanged();
    void stylePathChanged();

protected:
    void reposItems();
    void reinitImplicitSizes();

private:
    QPointer<QQmlComponent> mStyleComponent;
    QUrl mStylePath;
    AsemanQuickAbstractStyle *mStyleItem = nullptr;
};

#endif // ASEMANQUICKSTYLEDITEM_H

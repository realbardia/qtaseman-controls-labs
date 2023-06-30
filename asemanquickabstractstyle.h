#ifndef ASEMANQUICKABSTRACTSTYLE_H
#define ASEMANQUICKABSTRACTSTYLE_H

#include <QQuickItem>
#include <QFont>

#include "asemanquickboxsize.h"

class AsemanQuickAbstractStyle : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(AsemanQuickBoxSize *padding READ padding WRITE setPadding NOTIFY paddingChanged)
    Q_PROPERTY(QFont font READ font WRITE setFont NOTIFY fontChanged)

public:
    AsemanQuickAbstractStyle(QQuickItem *parent = nullptr);
    virtual ~AsemanQuickAbstractStyle();

    AsemanQuickBoxSize *padding() const;
    void setPadding(AsemanQuickBoxSize *newPadding);

    QFont font() const;
    void setFont(const QFont &newFont);

Q_SIGNALS:
    void paddingChanged();

    void fontChanged();

private:
    AsemanQuickBoxSize *mPadding;
    QFont mFont;
};

#endif // ASEMANQUICKABSTRACTSTYLE_H

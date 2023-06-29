#ifndef ASEMANQUICKABSTRACTSTYLE_H
#define ASEMANQUICKABSTRACTSTYLE_H

#include <QQuickItem>

class AsemanQuickAbstractStyle : public QQuickItem
{
    Q_OBJECT
public:
    AsemanQuickAbstractStyle(QQuickItem *parent = nullptr);
    virtual ~AsemanQuickAbstractStyle();

Q_SIGNALS:

};

#endif // ASEMANQUICKABSTRACTSTYLE_H

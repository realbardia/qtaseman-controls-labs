#ifndef ASEMANQUICKSTYLEATTACHEDPROPERTY_H
#define ASEMANQUICKSTYLEATTACHEDPROPERTY_H

#include <QObject>
#include <QtQml>
#include <QStringList>
#include <QColor>

class AsemanQuickStyleAttachedProperty : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList generalFontFamilies READ generalFontFamilies WRITE setGeneralFontFamilies NOTIFY generalFontFamiliesChanged)
    Q_PROPERTY(QColor highlightColor READ highlightColor WRITE setHighlightColor NOTIFY highlightColorChanged)
    Q_PROPERTY(QColor highlightTextColor READ highlightTextColor WRITE setHighlightTextColor NOTIFY highlightTextColorChanged)
    Q_PROPERTY(QColor foregroundColor READ foregroundColor WRITE setForegroundColor NOTIFY foregroundColorChanged)
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)

public:
    AsemanQuickStyleAttachedProperty(QObject *parent = nullptr);
    virtual ~AsemanQuickStyleAttachedProperty();

    QStringList generalFontFamilies() const;
    void setGeneralFontFamilies(const QStringList &newGeneralFontFamilies);

    QColor highlightColor() const;
    void setHighlightColor(const QColor &newHighlightColor);

    QColor highlightTextColor() const;
    void setHighlightTextColor(const QColor &newHighlightTextColor);

    QColor foregroundColor() const;
    void setForegroundColor(const QColor &newForegroundColor);

    QColor backgroundColor() const;
    void setBackgroundColor(const QColor &newBackgroundColor);

Q_SIGNALS:
    void generalFontFamiliesChanged();
    void highlightColorChanged();
    void highlightTextColorChanged();
    void foregroundColorChanged();
    void backgroundColorChanged();

private:
    QVariant mGeneralFontFamilies;
    QVariant mHighlightColor;
    QVariant mHighlightTextColor;
    QVariant mForegroundColor;
    QVariant mBackgroundColor;
};

class AsemanQuickStyleProperty : public QObject
{
    Q_OBJECT
public:
    static AsemanQuickStyleAttachedProperty *qmlAttachedProperties(QObject *object);
};

QML_DECLARE_TYPEINFO(AsemanQuickStyleProperty, QML_HAS_ATTACHED_PROPERTIES)

#endif // ASEMANQUICKSTYLEATTACHEDPROPERTY_H

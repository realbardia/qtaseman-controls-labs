#include "asemanquickstyleattachedproperty.h"

#include <QQuickItem>
#include <QDebug>

#define ASEMAN_READ_STYLE(PROPERTY) \
    auto parentObject = parent(); \
    auto res = PROPERTY; \
    while (res.isNull() && parentObject) { \
        auto attached = qobject_cast<AsemanQuickStyleAttachedProperty*>(qmlAttachedPropertiesObject<AsemanQuickStyleProperty>(parentObject, false)); \
        if (attached && !attached->PROPERTY.isNull()) { \
            res = attached->PROPERTY; \
            break; \
        } \
        parentObject = parentObject->parent(); \
    }

#define ASEMAN_WRITE_STYLE(PROPERTY, SIGNAL_NAME) \
    std::function<void(QObject *obj)> callback; \
    callback = [&callback](QObject *obj) { \
        for (auto c: obj->children()) { \
            auto attached = qobject_cast<AsemanQuickStyleAttachedProperty*>(qmlAttachedPropertiesObject<AsemanQuickStyleProperty>(c, false)); \
            if (!attached) { \
                callback(c); \
                continue; \
            } \
            if (attached->PROPERTY.isNull()) { \
                Q_EMIT attached->SIGNAL_NAME(); \
                callback(c); \
            } \
        } \
    }; \
    callback(parent());

AsemanQuickStyleAttachedProperty::AsemanQuickStyleAttachedProperty(QObject *parent)
    : QObject(parent)
{

}

AsemanQuickStyleAttachedProperty::~AsemanQuickStyleAttachedProperty()
{

}

QStringList AsemanQuickStyleAttachedProperty::generalFontFamilies() const
{
    ASEMAN_READ_STYLE(mGeneralFontFamilies);
    return res.toStringList();
}

void AsemanQuickStyleAttachedProperty::setGeneralFontFamilies(const QStringList &newGeneralFontFamilies)
{
    if (mGeneralFontFamilies == newGeneralFontFamilies)
        return;

    mGeneralFontFamilies = newGeneralFontFamilies;
    ASEMAN_WRITE_STYLE(mGeneralFontFamilies, generalFontFamiliesChanged);
    Q_EMIT generalFontFamiliesChanged();
}

QColor AsemanQuickStyleAttachedProperty::highlightColor() const
{
    ASEMAN_READ_STYLE(mHighlightColor);
    return res.value<QColor>();
}

void AsemanQuickStyleAttachedProperty::setHighlightColor(const QColor &newHighlightColor)
{
    if (mHighlightColor == newHighlightColor)
        return;
    mHighlightColor = newHighlightColor;
    ASEMAN_WRITE_STYLE(mHighlightColor, highlightColorChanged);
    Q_EMIT highlightColorChanged();
}

QColor AsemanQuickStyleAttachedProperty::highlightTextColor() const
{
    ASEMAN_READ_STYLE(mHighlightTextColor);
    return res.value<QColor>();
}

void AsemanQuickStyleAttachedProperty::setHighlightTextColor(const QColor &newHighlightTextColor)
{
    if (mHighlightTextColor == newHighlightTextColor)
        return;
    mHighlightTextColor = newHighlightTextColor;
    ASEMAN_WRITE_STYLE(mHighlightTextColor, highlightTextColorChanged);
    Q_EMIT highlightTextColorChanged();
}

QColor AsemanQuickStyleAttachedProperty::foregroundColor() const
{
    ASEMAN_READ_STYLE(mForegroundColor);
    return res.value<QColor>();
}

void AsemanQuickStyleAttachedProperty::setForegroundColor(const QColor &newForegroundColor)
{
    if (mForegroundColor == newForegroundColor)
        return;
    mForegroundColor = newForegroundColor;
    ASEMAN_WRITE_STYLE(mForegroundColor, foregroundColorChanged);
    Q_EMIT foregroundColorChanged();
}

QColor AsemanQuickStyleAttachedProperty::backgroundColor() const
{
    ASEMAN_READ_STYLE(mBackgroundColor);
    return res.value<QColor>();
}

void AsemanQuickStyleAttachedProperty::setBackgroundColor(const QColor &newBackgroundColor)
{
    if (mBackgroundColor == newBackgroundColor)
        return;
    mBackgroundColor = newBackgroundColor;
    ASEMAN_WRITE_STYLE(mBackgroundColor, backgroundColorChanged);
    Q_EMIT backgroundColorChanged();
}

AsemanQuickStyleAttachedProperty *AsemanQuickStyleProperty::qmlAttachedProperties(QObject *object)
{
    return new AsemanQuickStyleAttachedProperty(object);
}

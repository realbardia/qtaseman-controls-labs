#include "asemanquickstyleattachedproperty.h"

#include <QQuickItem>
#include <QDebug>

#define ASEMAN_READ_STYLE(PROPERTY) \
    auto parentObject = parent(); \
    auto res = PROPERTY; \
    while (!res.has_value() && parentObject) { \
        auto attached = qobject_cast<AsemanQuickStyleAttachedProperty*>(qmlAttachedPropertiesObject<AsemanQuickStyleProperty>(parentObject, false)); \
        if (attached && attached->PROPERTY.has_value()) { \
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
            if (!attached->PROPERTY.has_value()) { \
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
    return res.value_or(QStringList());
}

void AsemanQuickStyleAttachedProperty::setGeneralFontFamilies(const QStringList &newGeneralFontFamilies)
{
    if (mGeneralFontFamilies == newGeneralFontFamilies)
        return;

    mGeneralFontFamilies = newGeneralFontFamilies;
    ASEMAN_WRITE_STYLE(mGeneralFontFamilies, generalFontFamiliesChanged);
    Q_EMIT generalFontFamiliesChanged();
}

QColor AsemanQuickStyleAttachedProperty::accentColor() const
{
    ASEMAN_READ_STYLE(mAccentColor);
    return res.value_or(QColor());
}

void AsemanQuickStyleAttachedProperty::setAccentColor(const QColor &newHighlightColor)
{
    if (mAccentColor == newHighlightColor)
        return;
    mAccentColor = newHighlightColor;
    ASEMAN_WRITE_STYLE(mAccentColor, accentColorChanged);
    Q_EMIT accentColorChanged();
}

QColor AsemanQuickStyleAttachedProperty::accentTextColor() const
{
    ASEMAN_READ_STYLE(mAccentTextColor);
    return res.value_or(QColor());
}

void AsemanQuickStyleAttachedProperty::setAccentTextColor(const QColor &newHighlightTextColor)
{
    if (mAccentTextColor == newHighlightTextColor)
        return;
    mAccentTextColor = newHighlightTextColor;
    ASEMAN_WRITE_STYLE(mAccentTextColor, accentTextColorChanged);
    Q_EMIT accentTextColorChanged();
}

QColor AsemanQuickStyleAttachedProperty::foregroundColor() const
{
    ASEMAN_READ_STYLE(mForegroundColor);
    return res.value_or(QColor());
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
    return res.value_or(QColor());
}

void AsemanQuickStyleAttachedProperty::setBackgroundColor(const QColor &newBackgroundColor)
{
    if (mBackgroundColor == newBackgroundColor)
        return;
    mBackgroundColor = newBackgroundColor;
    ASEMAN_WRITE_STYLE(mBackgroundColor, backgroundColorChanged);
    Q_EMIT backgroundColorChanged();
}

QColor AsemanQuickStyleAttachedProperty::primaryColor() const
{
    ASEMAN_READ_STYLE(mPrimaryColor);
    return res.value_or(QColor());
}

void AsemanQuickStyleAttachedProperty::setPrimaryColor(const QColor &newPrimaryColor)
{
    if (mPrimaryColor == newPrimaryColor)
        return;
    mPrimaryColor = newPrimaryColor;
    ASEMAN_WRITE_STYLE(mPrimaryColor, primaryColorChanged);
    Q_EMIT primaryColorChanged();
}

QColor AsemanQuickStyleAttachedProperty::primaryTextColor() const
{
    ASEMAN_READ_STYLE(mPrimaryTextColor);
    return res.value_or(QColor());
}

void AsemanQuickStyleAttachedProperty::setPrimaryTextColor(const QColor &newPrimaryTextColor)
{
    if (mPrimaryTextColor == newPrimaryTextColor)
        return;
    mPrimaryTextColor = newPrimaryTextColor;
    ASEMAN_WRITE_STYLE(mPrimaryTextColor, primaryTextColorChanged);
    Q_EMIT primaryTextColorChanged();
}

AsemanQuickStyleAttachedProperty *AsemanQuickStyleProperty::qmlAttachedProperties(QObject *object)
{
    return new AsemanQuickStyleAttachedProperty(object);
}

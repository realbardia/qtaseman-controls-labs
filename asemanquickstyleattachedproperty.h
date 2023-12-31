#ifndef ASEMANQUICKSTYLEATTACHEDPROPERTY_H
#define ASEMANQUICKSTYLEATTACHEDPROPERTY_H

#include <QObject>
#include <QtQml>
#include <QStringList>
#include <QColor>

#include <optional>

class AsemanQuickStyleAttachedProperty : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList generalFontFamilies READ generalFontFamilies WRITE setGeneralFontFamilies NOTIFY generalFontFamiliesChanged)
    Q_PROPERTY(QColor accentColor READ accentColor WRITE setAccentColor NOTIFY accentColorChanged)
    Q_PROPERTY(QColor accentTextColor READ accentTextColor WRITE setAccentTextColor NOTIFY accentTextColorChanged)
    Q_PROPERTY(QColor foregroundColor READ foregroundColor WRITE setForegroundColor NOTIFY foregroundColorChanged)
    Q_PROPERTY(QColor backgroundColor READ backgroundColor WRITE setBackgroundColor NOTIFY backgroundColorChanged)
    Q_PROPERTY(QColor primaryColor READ primaryColor WRITE setPrimaryColor NOTIFY primaryColorChanged)
    Q_PROPERTY(QColor primaryTextColor READ primaryTextColor WRITE setPrimaryTextColor NOTIFY primaryTextColorChanged)
    Q_PROPERTY(QColor baseColor READ baseColor WRITE setBaseColor NOTIFY baseColorChanged)
    Q_PROPERTY(QColor baseTextColor READ baseTextColor WRITE setBaseTextColor NOTIFY baseTextColorChanged)
    Q_PROPERTY(QString styleName READ styleName WRITE setStyleName NOTIFY styleNameChanged)
    Q_PROPERTY(QStringList stylesSearchPath READ stylesSearchPath WRITE setStylesSearchPath NOTIFY stylesSearchPathChanged)
    Q_PROPERTY(QUrl styleUrl READ styleUrl NOTIFY styleNameChanged)

public:
    AsemanQuickStyleAttachedProperty(QObject *parent = nullptr);
    virtual ~AsemanQuickStyleAttachedProperty();

    QStringList generalFontFamilies() const;
    void setGeneralFontFamilies(const QStringList &newGeneralFontFamilies);

    QColor accentColor() const;
    void setAccentColor(const QColor &newHighlightColor);

    QColor accentTextColor() const;
    void setAccentTextColor(const QColor &newHighlightTextColor);

    QColor foregroundColor() const;
    void setForegroundColor(const QColor &newForegroundColor);

    QColor backgroundColor() const;
    void setBackgroundColor(const QColor &newBackgroundColor);

    QColor primaryColor() const;
    void setPrimaryColor(const QColor &newPrimaryColor);

    QColor primaryTextColor() const;
    void setPrimaryTextColor(const QColor &newPrimaryTextColor);

    QColor baseColor() const;
    void setBaseColor(const QColor &newBaseColor);

    QColor baseTextColor() const;
    void setBaseTextColor(const QColor &newBaseTextColor);

    QString styleName() const;
    void setStyleName(const QString &newStyleName);

    QStringList stylesSearchPath() const;
    void setStylesSearchPath(const QStringList &newStylesSearchPath);

    static QString getStylePath(const QStringList &searchPaths, const QString &styleName);
    QUrl styleUrl() const;

Q_SIGNALS:
    void generalFontFamiliesChanged();
    void accentColorChanged();
    void accentTextColorChanged();
    void foregroundColorChanged();
    void backgroundColorChanged();
    void primaryColorChanged();
    void primaryTextColorChanged();
    void baseColorChanged();
    void baseTextColorChanged();
    void styleNameChanged();
    void stylesSearchPathChanged();
    void styleUrlChanged();

protected:
    void invokeAllSignals();
    static QObject *findParent(const QObject *obj);

private:
    std::optional<QStringList> mGeneralFontFamilies;

    std::optional<QString> mStyleName;
    std::optional<QStringList> mStylesSearchPath;

    std::optional<QColor> mPrimaryColor;
    std::optional<QColor> mPrimaryTextColor;
    std::optional<QColor> mAccentColor;
    std::optional<QColor> mAccentTextColor;
    std::optional<QColor> mForegroundColor;
    std::optional<QColor> mBackgroundColor;
    std::optional<QColor> mBaseColor;
    std::optional<QColor> mBaseTextColor;

    static QHash<QString, QHash<QString, QString>> mThemePaths;
};

class AsemanQuickStyleProperty : public QObject
{
    Q_OBJECT
public:
    static AsemanQuickStyleAttachedProperty *qmlAttachedProperties(QObject *object);
};

QML_DECLARE_TYPEINFO(AsemanQuickStyleProperty, QML_HAS_ATTACHED_PROPERTIES)

#endif // ASEMANQUICKSTYLEATTACHEDPROPERTY_H

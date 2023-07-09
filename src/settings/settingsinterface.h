#ifndef SETTINGSINTERFACE_H
#define SETTINGSINTERFACE_H

#include <QObject>

class SettingsInterface : public QObject
{
    Q_OBJECT
public:
    explicit SettingsInterface(QObject *parent = nullptr);

public slots:
    QString getStringValue(const QString &key);

    int getIntValue(const QString& key);

    double getDoubleValue(const QString &key);

    bool saveValue(const QString &key, const QVariant& value, const QString& type);

signals:

};

#endif // SETTINGSINTERFACE_H

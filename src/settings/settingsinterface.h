#ifndef SETTINGSINTERFACE_H
#define SETTINGSINTERFACE_H

#include <QObject>
#include <QVariant>

class SettingsInterface : public QObject
{
    Q_OBJECT
public:
    explicit SettingsInterface(QObject *parent = nullptr);

public slots:
    QVariant getValue(const QString &key, const QString &type);

    bool saveValue(const QString &key, const QVariant& value, const QString& type);

signals:

};

#endif // SETTINGSINTERFACE_H

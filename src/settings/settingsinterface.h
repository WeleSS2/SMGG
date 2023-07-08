#ifndef SETTINGSINTERFACE_H
#define SETTINGSINTERFACE_H

#include <QObject>

class SettingsInterface : public QObject
{
    Q_OBJECT
public:
    explicit SettingsInterface(QObject *parent = nullptr);

signals:

};

#endif // SETTINGSINTERFACE_H

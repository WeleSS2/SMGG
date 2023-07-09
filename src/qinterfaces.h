#ifndef QINTERFACES_H
#define QINTERFACES_H

#include <QObject>
#include <QVector>
#include <QPair>
#include <QQmlApplicationEngine>

class QInterfaces : public QObject
{
    Q_OBJECT
public:
    explicit QInterfaces(QObject *parent = nullptr, QQmlApplicationEngine *engine = nullptr);

    ~QInterfaces();

    // Build all qml interfaces
    bool BuildAll();

    // Close all qml interfaces
    bool CloseAll();

signals:


private:
    QQmlApplicationEngine *engine;
};

#endif // QINTERFACES_H

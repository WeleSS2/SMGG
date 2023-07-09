#pragma once

#include <QObject>

class ApplicationInterface : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationInterface(QObject *parent = nullptr);

public slots:
    // When app started
    bool appUp();

    // When app closed
    bool appDown();

private:
};

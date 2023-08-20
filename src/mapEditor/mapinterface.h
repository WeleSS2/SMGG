#ifndef MAPINTERFACE_H
#define MAPINTERFACE_H

#include <QObject>

class MapInterface : public QObject
{
    Q_OBJECT
public:
    explicit MapInterface(QObject *parent = nullptr);

signals:

};

#endif // MAPINTERFACE_H

#include "qgalaxymaplist.h"

//TODO

QGalaxyMapList::QGalaxyMapList(QObject *parent)
{


    _galaxiesPtr = std::make_unique<QVector<std::shared_ptr<Galaxy>>>(_currentMap->getMap()->getGalaxies());
}

int QGalaxyMapList::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() || !_currentMap.get())
        return 0;

    return _galaxiesPtr->size();
}

QVariant QGalaxyMapList::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !_currentMap.get())
        return 0;

    return 0;
}

bool QGalaxyMapList::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return 0;
}

Qt::ItemFlags QGalaxyMapList::flags(const QModelIndex &data) const
{
    return Qt::ItemFlag();
}

QHash<int, QByteArray> QGalaxyMapList::roleNames() const
{
    return {};
}

QGalaxyMap QGalaxyMapList::*getList()
{
    return nullptr;
}

void QGalaxyMapList::setList(QGalaxyMap *list)
{

}

//---------------------------------------------------
//
//                      QSystems
//
//---------------------------------------------------

QSystemsMapList::QSystemsMapList(QObject *parent)
{

}

int QSystemsMapList::rowCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant QSystemsMapList::data(const QModelIndex &index, int role) const
{
    return 0;
}

bool QSystemsMapList::setData(const QModelIndex &index, const QVariant &value, int role)
{
    return 0;
}

Qt::ItemFlags QSystemsMapList::flags(const QModelIndex &data) const
{
    return Qt::ItemFlag();
}

QHash<int, QByteArray> QSystemsMapList::roleNames() const
{
    return {};
}

QGalaxyMap QSystemsMapList::*getSystems()
{
    return nullptr;
}

#include "qgalaxymaplist.h"

QGalaxyMapList::QGalaxyMapList(QObject *parent)
{

}

int QGalaxyMapList::rowCount(const QModelIndex &parent) const
{
    return 0;
}

QVariant QGalaxyMapList::data(const QModelIndex &index, int role) const
{
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

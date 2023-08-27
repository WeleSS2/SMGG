#ifndef QGALAXYMAPLIST_H
#define QGALAXYMAPLIST_H

#include <QAbstractListModel>

#include "qgalaxymap.h"
#include "qsystemsmap.h"

//---------------------------------------------------------------------------------
//  Display for repeaters of current map
//

// Pre-definition of Galaxy map
//class QGalaxyMap;

// Galaxy model which will display galaxies
class QGalaxyMapList : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit QGalaxyMapList(QObject *parent = nullptr);

    enum {
        GalaxyId,
        GalaxyPosition,
        Systems
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    QGalaxyMap *getList;

    void setList(QGalaxyMap *list);

private:
    std::unique_ptr<QGalaxyMap> _currentMap;
};

//
//
// Predefinition of systems list
//class QSystemsMap;

// Model for inner systems in galaxy list model
class QSystemsMapList : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit QSystemsMapList(QObject *parent = nullptr);

    enum {
        SystemId,
        SystemPosition,
        SystemInitializer,
        InitializerID,
        StarType,
        PlayerID
    };

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    QSystemsMap *getSystems;

private:
    std::unique_ptr<QSystemsMap> _Systems;
};

#endif // QGALAXYMAPLIST_H

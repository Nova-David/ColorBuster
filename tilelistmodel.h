
#ifndef TILELISTMODEL_H
#define TILELISTMODEL_H


#include <QAbstractListModel>
#include <QList>
#include <algorithm>
#include "tile.h"


class TileListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit TileListModel(QObject *parent = nullptr);

    enum {
        ColorRole = Qt::UserRole,
        TypeRole,
        XPosRole,
        YPosRole
    };

    void setSize(int, int);
    std::string toString();
    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    void insert(Tile *tile);
    void append(Tile *tile);
    void remove(Tile *tile);
    void sendSignal();
    void clear();

signals:
    void tileAdded();
    void tileRemoved();

private:
    QList<Tile*> m_tiles;
    int m_cols;
    int m_rows;
};

#endif // TILELISTMODEL_H

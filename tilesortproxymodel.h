#ifndef TILESORTPROXYMODEL_H
#define TILESORTPROXYMODEL_H

#include <QSortFilterProxyModel>

#include "tilelistmodel.h"

class TileSortProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit TileSortProxyModel(QObject *parent = nullptr);

    void setSourceModel(QAbstractItemModel *sourceModel) override;

protected:
    bool lessThan(const QModelIndex &left, const QModelIndex &right) const override;

private:
    TileListModel *m_tileList = nullptr;
};

#endif // TILESORTPROXYMODEL_H

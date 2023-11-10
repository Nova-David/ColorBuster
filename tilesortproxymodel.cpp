
#include "tilesortproxymodel.h"
#include "tilelistmodel.h"
#include "tile.h"

TileSortProxyModel::TileSortProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
}

void TileSortProxyModel::setSourceModel(QAbstractItemModel *sourceModel)
{
    QSortFilterProxyModel::setSourceModel(sourceModel);

    m_tileList = qobject_cast<TileListModel*>(sourceModel);
}

bool TileSortProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{

//    qDebug() << "lessThan called with left:" << left << "right:" << right;
    QVariant leftDataX = sourceModel()->data(left, TileListModel::XPosRole);
    QVariant rightDataX = sourceModel()->data(right, TileListModel::XPosRole);
    QVariant leftDataY = sourceModel()->data(left, TileListModel::YPosRole);
    QVariant rightDataY = sourceModel()->data(right, TileListModel::YPosRole);

    if (leftDataX.userType() == qMetaTypeId<int>()) {

        if (leftDataY == rightDataY) {
//            qDebug() << leftDataX << ", " << leftDataY << " less than " << rightDataX << ", " << rightDataY;
            return leftDataX.toInt() < rightDataX.toInt();
        }
        return leftDataY.toInt() < rightDataY.toInt();
    }

    return QSortFilterProxyModel::lessThan(left, right);
}

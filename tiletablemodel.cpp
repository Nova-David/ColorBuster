//#include "tiletablemodel.h"

//TileTableModel::TileTableModel(QObject *parent)
//    : QAbstractTableModel(parent)
//{
//}

//std::string TileTableModel::toString() {
//    std::string result = "";

//    for (int row = 0; row < m_rows; row++) {
//        for (int col = 0; col < m_cols; col++) {
//            int color = -1;

//            int index = row * m_cols + col;
//            if (index < m_tiles.size()) {
//                color = m_tiles[index].color;
//            }

//            std::string colorStr;

//            switch (color) {
//            case 0:
//                colorStr = "O";
//                break;
//            case 1:
//                colorStr = "G";
//                break;
//            case 2:
//                colorStr = "Y";
//                break;
//            case 3:
//                colorStr = "R";
//                break;
//            default:
//                colorStr = "-";
//            }

//            result += colorStr + " ";
//        }

//        result += "\n";
//    }

//    return result;
//}

//int TileTableModel::rowCount(const QModelIndex &parent) const
//{
//    Q_UNUSED(parent);
//    return m_rows;
//}

//int TileTableModel::columnCount(const QModelIndex &parent) const
//{
//    Q_UNUSED(parent);
//    return m_cols;
//}

//QVariant TileTableModel::data(const QModelIndex &index, int role) const
//{
//    if (!index.isValid() || index.row() >= m_rows || index.column() >= m_cols) {
//        return QVariant();
//    }

//    int tileIndex = index.row() * m_cols + index.column();
//    const TileData &tile = m_tiles[tileIndex];

//    if (role == ColorRole) {
//        return tile.color;
//    } else if (role == TypeRole) {
//        return tile.type;
//    }

//    return QVariant();
//}

//QHash<int, QByteArray> TileTableModel::roleNames() const
//{
//    static QHash<int, QByteArray> mapping {
//        {ColorRole, "color"},
//        {TypeRole, "type"}
//    };

//    return mapping;
//}

//bool TileTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    if (!index.isValid() || role != Qt::EditRole) {
//        return false;
//    }

//    int tileIndex = index.row() * m_cols + index.column();
//    TileData &tile = m_tiles[tileIndex];

//    if (value.canConvert<int>()) {
//        int intValue = value.toInt();
//        if (role == ColorRole) {
//            tile.color = intValue;
//        } else if (role == TypeRole) {
//            tile.type = intValue;
//        }
//        emit dataChanged(index, index, {role});
//        return true;
//    }

//    return false;
//}

//Qt::ItemFlags TileTableModel::flags(const QModelIndex &index) const
//{
//    if (!index.isValid()) {
//        return Qt::NoItemFlags;
//    }

//    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
//}

//void TileTableModel::append(TileData tile, int col, int row)
//{
//    int index = row * m_cols + col;
//    beginInsertRows(QModelIndex(), index, index);
//    m_tiles.insert(index, tile);
//    endInsertRows();
//    emit tileAdded();
//}

//void TileTableModel::remove(int col, int row)
//{
//    int index = row * m_cols + col;

//    if (index >= m_tiles.size()) return;

//    beginRemoveRows(QModelIndex(), index, index);
//    m_tiles.removeAt(index);
//    endRemoveRows();

//    // Move tiles down to fill the empty space
//    for (int r = row + 1; r < m_rows; r++) {
//        int tileIndex = r * m_cols + col;

//        // Move the tile down
//        TileData tile = m_tiles[tileIndex];
//        m_tiles[tileIndex] = TileData();
//        int newIndex = (r - 1) * m_cols + col;
//        m_tiles[newIndex] = tile;

//        // Update the model
//        QModelIndex oldIndex = createIndex(r, col);
//        QModelIndex newModelIndex = createIndex(r - 1, col);
//        emit dataChanged(oldIndex, newModelIndex, {ColorRole, TypeRole});
//    }

//    emit tileRemoved();
//}

//void TileTableModel::setSize(int col, int row) {
//    m_cols = col;
//    m_rows = row;
//}


#include "tilelistmodel.h"

TileListModel::TileListModel(QObject *parent)
    : QAbstractListModel(parent)
{}

int TileListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_tiles.count();
}

std::string TileListModel::toString() {
    std::string result = "";

    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            int color = -1;

            for (int k = 0; k < m_tiles.size(); k++) {
                int pos[2] = {m_tiles.at(k)->getPos()[0], m_tiles.at(k)->getPos()[1]};

                if (pos[0] == i && pos[1] == j) {
                    color = m_tiles.at(k)->getColor();
                    break;
                }
            }

            std::string colorStr;

            switch (color) {
            case 0:
                colorStr = "O";
                break;
            case 1:
                colorStr = "G";
                break;
            case 2:
                colorStr = "Y";
                break;
            case 3:
                colorStr = "R";
                break;
            default:
                colorStr = "-";
            }

            result += colorStr + " ";
        }

        result += "\n";
    }

    return result;
}

QVariant TileListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    Tile* tile = m_tiles.at(index.row());

    if (role == ColorRole)
        return tile->getColor();
    else if (role == TypeRole)
        return tile->getType();
    else if (role == XPosRole)
        return tile->getPos()[0];
    else if (role == YPosRole)
        return tile->getPos()[1];
    else
        return QVariant();
}

QHash<int, QByteArray> TileListModel::roleNames() const
{
    static QHash<int, QByteArray> mapping {
        {ColorRole, "color"},
        {TypeRole, "type"},
        {XPosRole, "xPos"},
        {YPosRole, "yPos"}
    };

    return mapping;
}

void TileListModel::append(Tile* tile)
{
    for (int i = 0; i < m_tiles.size(); i++) {
        if (m_tiles[i]->getPos()[0] == tile->getPos()[0] &&
            m_tiles[i]->getPos()[1] == tile->getPos()[1]) {
            remove(m_tiles[i]);
            break;
        }
    }


    int index = m_tiles.size();
    beginInsertRows(QModelIndex(), index, index);
    m_tiles.append(tile);
//    qDebug() << tile->getPos()[0] << ", " << tile->getPos()[1] << ", " << tile->getColor() << ", tile List adding";
    std::sort(m_tiles.begin(), m_tiles.end(), [] (Tile *a, Tile *b) {
        if (a->getPos()[1] == b->getPos()[1])
            return a->getPos()[0] < b->getPos()[0];
        return a->getPos()[1] < b->getPos()[1];
    });
    endInsertRows();

    emit tileAdded();
}

void TileListModel::setSize(int x, int y) {
    m_cols = x;
    qDebug() << m_cols << "Her?";
    m_rows = y;
}

void TileListModel::insert(Tile* tile)
{
    int col = tile->getPos()[0];
    int row = tile->getPos()[1];


    for (int i = 0; i < m_tiles.size(); i++) {
        if (m_tiles[i]->getPos()[0] == col &&
            m_tiles[i]->getPos()[1] == row) {
            remove(m_tiles[i]);
            break;
        }
    }


    int index = row * m_cols + col;
    beginInsertRows(QModelIndex(), index, index);
    m_tiles.insert(index, tile);
    std::sort(m_tiles.begin(), m_tiles.end(), [] (Tile *a, Tile *b) {
        if (a->getPos()[1] == b->getPos()[1])
            return a->getPos()[0] < b->getPos()[0];
        return a->getPos()[1] < b->getPos()[1];
    });
    endInsertRows();
;
    emit tileAdded();
}

void TileListModel::remove(Tile* tile)
{
    int index = m_tiles.indexOf(tile);

    if (index >= 0) {
//        qDebug() << tile->getPos()[0] << ", " << tile->getPos()[1] << ", " << tile->getColor() << ", tile List removing";
        beginRemoveRows(QModelIndex(), index, index);
        m_tiles.removeAt(index);
        endRemoveRows();

        emit tileRemoved();
    }
}

void TileListModel::clear()
{
    int rows = m_tiles.count();
    if (rows > 0) {
        beginRemoveRows(QModelIndex(), 0, rows - 1);
        m_tiles.clear();
        endRemoveRows();
    }
}

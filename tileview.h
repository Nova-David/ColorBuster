
#ifndef TILEVIEW_H
#define TILEVIEW_H


#include <QObject>
#include "Tile.h"

class TileView : public QObject
{
    Q_OBJECT
public:
    explicit TileView(QObject *parent = nullptr);

signals:
    void tileDestroyed(Tile* tile);

public slots:
    void destroy(Tile* tile) {
        emit tileDestroyed(tile);
    }
};

#endif // TILEVIEW_H

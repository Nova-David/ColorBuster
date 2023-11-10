
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Game.h"
#include "board.h"
#include <QObject>
#include <QSize>
#include <QTimer>
#include "score.h"
#include "tilelistmodel.h"
#include "tilesortproxymodel.h"

class GameController : public QObject
{
    Q_OBJECT
    Q_PROPERTY (int state READ getState NOTIFY stateChanged)
    Q_PROPERTY (QSize boardSize READ getBoardSize NOTIFY sizeChanged)
private:
    Game* game;
    Board* board;
    Score* score;
    TileListModel tileList;
    TileSortProxyModel tileProxyModel;
    QSize m_boardSize;
    QTimer timer;
    QMetaObject::Connection timerConnection;

public:
    GameController(QObject *parent = nullptr);
    ~GameController();

    void matchSize(int, int);
    void startGame();
    void onTouch(Tile*);
    void restartGame();
    Score& getScore();
    int getState();
    QSize getBoardSize();
    TileListModel& getTileList();
    TileSortProxyModel& getTileProxyModel();
    Q_INVOKABLE void onTouch(int x, int y);
    Q_INVOKABLE void chooseBoard(int, int);
    Q_INVOKABLE void tryAgain();
    void gameOver();

signals:
    void scoreChanged();
    void stateChanged();
    void sizeChanged();
};

#endif // GAMECONTROLLER_H

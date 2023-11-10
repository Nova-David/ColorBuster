
#include "gamecontroller.h"

GameController::GameController(QObject *parent) : QObject(parent)
{
    game = new Game();
    score = new Score(10);
    //viewHandler.createView(GameView, game)
}

GameController::~GameController() {
    delete game;
    delete score;
    delete board;
}

void GameController::matchSize(int m, int n)
{
    board = new Board(m, n);
    tileList.setSize(m, n);
    emit sizeChanged();

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            Tile* tile = board->getTile(i, j);
            tileList.append(tile);

//            tileTable.append({tile->getColor(), tile->getType()}, tile->getPos()[0], tile->getPos()[1]);
        }
    }

    qDebug().noquote() << board->toString();
    qDebug().noquote() << "TILELIST\n" << tileList.toString();

    startGame();
}

void GameController::startGame() {
    if (board) {
        game->setState(Game::InGame);
        emit stateChanged();
        //viewHandler.update(GameView)
        score->setScore(10);
        emit scoreChanged();
        disconnect(timerConnection);
        timer.setInterval(2000);
        timerConnection = connect(&timer, &QTimer::timeout, [this] () {
            score->take(2);
            emit scoreChanged();

            if (score->getScore() <= 0) gameOver();
        });
        timer.start();

    }
}

void GameController::onTouch(Tile* tile) {
    std::vector<Tile*> matches = board->findMatches(tile->getPos());

    if (matches.size() >= 3) {
        score->add(matches.size() - 2);
        emit scoreChanged();
        //viewHandler.update(ScoreView)
        std::vector<Tile*> newTiles = board->removeTiles(matches);

        for (auto& tile : newTiles) {
            //viewHandler.createView(TileView, tile, boardView)
        }

        if (board->checkGameOver()) {
            game->setState(Game::GameOver);
            emit stateChanged();
            //viewHandler.update(GameView)
        }
    }
}

void GameController::onTouch(int x, int y) {
//    qDebug() << x << ", " << y << " touched";
    qDebug() << board->getTile(x, y)->getColor() << " color";
    std::vector<Tile*> matches = board->findMatches(new int[2] {x, y});

    if (matches.size() >= 3) {
        qDebug() << matches.size() << " tiles found matching";
        score->add(matches.size() - 2);
        emit scoreChanged();

        for (auto& tile : matches) {
            tileList.remove(tile);
//            tileTable.remove(tile->getPos()[0], tile->getPos()[1]);
        }

        std::vector<Tile*> newTiles = board->removeTiles(matches);

        for (auto& tile : newTiles) {
//            tileTable.append({tile->getColor(), tile->getType()}, tile->getPos()[0], tile->getPos()[1]);
            tileList.insert(tile);
        }

        tileProxyModel.sort(0);

        qDebug().noquote() << "TILELIST\n" << tileList.toString();
//            qDebug().noquote() << "TILE TABLE\n" << tileTable.toString();

//        qDebug().noquote() << board->toString();

        if (board->checkGameOver()) {
            gameOver();
            //viewHandler.update(GameView)
        }
    } else {
        score->take(3);
        emit scoreChanged();
    }
}

void GameController::restartGame() {
    timer.stop();
    disconnect(timerConnection);
    game->setState(Game::StartScreen);
    emit stateChanged();
    tileList.clear();
}

int GameController::getState() {
    return game->getState();
}

Score& GameController::getScore() {
    return *score;
}

QSize GameController::getBoardSize() {
    return m_boardSize;
}

TileListModel& GameController::getTileList() {
    return tileList;
}

TileSortProxyModel& GameController::getTileProxyModel() {
    return tileProxyModel;
}

void GameController::chooseBoard(int m, int n) {
    m_boardSize = QSize(m, n);
    emit sizeChanged();
    matchSize(m, n);
}

void GameController::tryAgain() {
    restartGame();
}

void GameController::gameOver() {
    qDebug() << "Here I am";
    game->setState(Game::GameOver);
    emit stateChanged();
}



//TileTableModel& GameController::getTileTable() {
//    return tileTable;
//}

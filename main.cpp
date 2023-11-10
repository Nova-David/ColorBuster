#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Tile.h"
#include "Board.h"
#include "Score.h"
#include "GameController.h"
#include "tilelistmodel.h"
#include "tilesortproxymodel.h"
#include "ScoreView.h"

void debugScore(Score& score, int* scores) {
    for (int i = 0; i < sizeof(scores); i++) {
        score.setScore(scores[i]);
        score.updateHighScore();
        qDebug() << "Current score: " << score.getScore();
        qDebug() << "High scores: " << QString::fromStdString(score.toString());
    }
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;


//    Tile* myTile = new Tile(0, 0, new int[2] {0, 0});
//    myTile->setPos(new int[2] {3, 6});
//    qDebug() << "New tile: " << myTile->toString();
//    delete myTile;

//    Board* myBoard = new Board(5, 5);
//    qDebug().noquote() << myBoard->toString();
//    qDebug() << myBoard->checkGameOver();
//    delete myBoard;

//    Score* myScore = new Score(5);

//    int scores[9] = {4, 1, 7, 3, 1, 5, 3, 4, 9};
//    debugScore(*myScore, scores);

//    delete myScore;




    QQmlContext* context = engine.rootContext();
    context->setContextProperty("_title", QString("ColorBuster"));

    GameController* controller = new GameController();

    ScoreView* scoreView = new ScoreView();
    scoreView->setScore(&controller->getScore());

    QObject::connect(controller, &GameController::scoreChanged,
                     scoreView, &ScoreView::scoreChanged);

    context->setContextProperty("_score", scoreView);

    TileListModel& tileList = controller->getTileList();
    TileSortProxyModel& tileProxyModel = controller->getTileProxyModel();
    tileProxyModel.setSourceModel(&tileList);
//    tileProxyModel.sort(0, Qt::AscendingOrder);
//    tileProxyModel.setDynamicSortFilter(true);

    context->setContextProperty("_controller", controller);
    context->setContextProperty("_tileList", &tileProxyModel);

    const QUrl url(u"qrc:/ColorBuster/Main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.load(url);


    return app.exec();
}

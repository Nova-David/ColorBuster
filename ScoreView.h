
#ifndef SCOREVIEW_H
#define SCOREVIEW_H

#include <QObject>
#include <QString>
#include <QList>
#include "Score.h"

class ScoreView : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int current READ current NOTIFY scoreChanged)

public:
    explicit ScoreView(QObject *parent = nullptr) : QObject(parent), m_score(nullptr) {}

    int current() const {
        if (m_score)
            return m_score->getScore();

        return 0;
    }

    void setScore(Score* score) {
        m_score = score;
        emit scoreChanged();
    }

signals:
    void scoreChanged();

private:
    Score* m_score;
};

#endif // SCOREVIEW_H

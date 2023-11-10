
#include "score.h"

Score::Score(int size)
    : highScores(size, -1) {}

std::string Score::toString() const {
    std::string result = "[";
    bool first = true;

    for (int i : highScores) {
        if (i != -1) {
            if (!first) result += ", ";
            result += std::to_string(i);
            first = false;
        }
    }

    result += "]";
    return result;
}

void Score::updateHighScore() {
    if (highScores[0] == -1 || score > highScores[0]) {
        highScores[0] = score;
        std::sort(highScores.begin(), highScores.end());
    }
}

int Score::getScore() const {
    return score;
}

void Score::setScore(int score) {
    this->score = score;
}

void Score::add(int score) {
    this->score += score;
}

void Score::take(int score) {
    this->score -= score;
    if (this->score < 0) this->score = 0;
}

std::vector<int> Score::getHighScores() const {
    return highScores;
}


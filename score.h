
#ifndef SCORE_H
#define SCORE_H

#include <vector>
#include <algorithm>
#include <string>

class Score
{
private:
    int score;
    std::vector<int> highScores;
public:
    Score(int);
    std::string toString() const;

    void updateHighScore();
    int getScore() const;
    void setScore(int);
    void add(int);
    void take(int);
    std::vector<int> getHighScores() const;
};

#endif // SCORE_H

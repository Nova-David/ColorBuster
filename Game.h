
#ifndef GAME_H
#define GAME_H

class Game {
private:
    int state;

public:
    static const int Colors = 4;
    static const int TileTypes = 1;
    enum GameState {
        StartScreen, InGame, GameOver
    };

    Game() { state = 0; }

    int getState() const { return state; }
    void setState(int state) { this->state = state; }

};

#endif // GAME_H

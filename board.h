
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

#include "tile.h"
#include "Game.h"

class Board
{
private:
    Tile** tiles;
    int size[2];

    void createBoard();
    void dfs(int, int, int, std::vector<std::vector<bool>>&, std::vector<Tile*>&);

public:
    Board(int, int);
    ~Board();
    std::string toString();

    Tile* getTile(int, int) const;
    std::vector<Tile*> findMatches(int*);
    std::vector<Tile*> removeTiles(std::vector<Tile*>&);
    std::vector<Tile*> addNewTiles();
    bool checkGameOver();

};

#endif // BOARD_H

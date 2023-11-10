
#include "board.h"
#include <QDebug>

Board::Board(int m, int n)
{
    size[0] = m;
    size[1] = n;

    createBoard();
}

Board::~Board()
{
    for (int i = 0; i < size[0]; i++)
        delete[] tiles[i];

    delete[] tiles;
}

//std::string Board::toString() {
////    std::string result = "Display board";
//    std::string result = "";
//    for (int i = 0; i < size[0]; i++)
//        for (int j = 0; j < size[1]; j++)
//            result += tiles[i][j].toString() + "\n";

//    return result;
//}

std::string Board::toString() {
    std::string result = "\n";
    for (int i = 0; i < size[1]; i++) {
        result += " ";
        for (int j = 0; j < size[0]; j++) {
            char abbrev;
            switch (tiles[j][i].getColor()) {
            case 0:
                abbrev = 'O';
                break;
            case 1:
                abbrev = 'G';
                break;
            case 2:
                abbrev = 'Y';
                break;
            case 3:
                abbrev = 'R';
                break;
            default:
                abbrev = '?';
                break;
            }
            result += tiles[j][i].isNull() ? 'X' : abbrev;
            result += " ";
        }
        result += "\n";
    }

    return result;
}

Tile* Board::getTile(int m, int n) const {
    return &tiles[m][n];
}

void Board::createBoard()
{
    int m = size[0];
    int n = size[1];
    tiles = new Tile*[m];

    std::srand(std::time(NULL));

    for (int i = 0; i < m; i++) {
        tiles[i] = new Tile[n];

        for (int j = 0; j < n; j++) {
            int color = std::rand() % Game::Colors;
            int type =  std::rand() % Game::TileTypes;
            int pos[2] = {i, j};
            tiles[i][j].set(color, type, pos);
        }
    }

    int x = std::rand() % m;
    int y = std::rand() % n;
    int pos[2] = {x, y};
    int color = std::rand() % Game::Colors;
    int type = std::rand() % Game::TileTypes;

    qDebug() << "TileA " << x << " " << y;
    Tile tileA(color, type, pos);
    tiles[x][y] = tileA;

    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int* change;
    int dx, dy;

    do {
        change = directions[std::rand() % 4];
        dx = change[0];
        dy = change[1];
    } while (x + dx == m ||
             x + dx == -1 ||
             y + dy == n ||
             y + dy == -1);

    x = x + dx;
    y = y + dy;
    pos[0] = x, pos[1] = y;

    qDebug() << "TileB " << x << " " << y;
    Tile tileB(color, type, pos);
    tiles[x][y] = tileB;

    do {
        change = directions[std::rand() % 4];
        dx = change[0];
        dy = change[1];
    } while (x + dx == m ||
             x + dx == -1 ||
             y + dy == n ||
             y + dy == -1 ||
             (x + dx == tileA.getPos()[0] && y + dy == tileB.getPos()[1]));

    x = x + dx;
    y = y + dy;
    pos[0] = x, pos[1] = y;

    qDebug() << "TileC " << x << " " << y;
    Tile tileC(color, type, pos);
    tiles[x][y] = tileC;
}

std::vector<Tile*> Board::findMatches (int pos[2]) {
    int x = pos[0];
    int y = pos[1];

    int color = tiles[x][y].getColor();

    std::vector<std::vector<bool>> visited(size[0], std::vector<bool>(size[1], false));

    std::vector<Tile*> matchingTiles;

    dfs(x, y, color, visited, matchingTiles);

    return matchingTiles;
}

void Board::dfs(int x, int y, int color, std::vector<std::vector<bool>>& visited, std::vector<Tile*>& matchingTiles) {
    if (x < 0 || x >= size[0] || y < 0 || y >= size[1] || visited[x][y])
        return;

    if (tiles[x][y].getColor() != color)
        return;

    visited[x][y] = true;
    matchingTiles.push_back(&tiles[x][y]);

    dfs(x + 1, y, color, visited, matchingTiles);
    dfs(x - 1, y, color, visited, matchingTiles);
    dfs(x, y + 1, color, visited, matchingTiles);
    dfs(x, y - 1, color, visited, matchingTiles);
}

std::vector<Tile*> Board::removeTiles(std::vector<Tile*>& givenTiles) {
    for (auto& tile : givenTiles) {
        int x = tile->getPos()[0];
        int y = tile->getPos()[1];
        qDebug() << x <<  ", " << y << " removed";
        tiles[x][y].remove();
    }

    return addNewTiles();
}

std::vector<Tile*> Board::addNewTiles() {
    std::vector<Tile*> newTiles;

    qDebug().noquote() << this->toString();

    std::srand(std::time(NULL));

    for (int k = size[0] - 1; k >= 0; k--) {
        int i = 0;

        for (int j = size[1] - 1; j >= 0; j--)
            if (!tiles[k][j].isNull()) {

                if (j != size[1] - 1 - i) {
                    int color = tiles[k][j].getColor();
                    int type = tiles[k][j].getType();
                    int pos[2] = {k, size[1] - 1 - i};
                    Tile tile(color, type, pos);
                    tiles[k][size[1] - 1 - i] = tile;
                    newTiles.push_back(&tiles[k][size[1] - 1 - i]);
                }
//                qDebug() << "{" << k << "," << j << " changed to " << k << "," << size[1] - 1 - i;
                i++;
            }

        for (int n = size[1] - 1 - i; n >= 0; n--) {
            int color = std::rand() % Game::Colors;
            int type = std::rand() % Game::TileTypes;
            int pos[2] = {k, n};
            Tile tile(color, type, pos);
            qDebug() << "New tile at " << k << ", " << n;
            tiles[k][n] = tile;
            newTiles.push_back(&tiles[k][n]);
        }
    }

    qDebug().noquote() << this->toString();
    std::reverse(newTiles.begin(), newTiles.end());

    return newTiles;
}

bool Board::checkGameOver() {
    for (int j = 0; j < size[0]; j++)
        for (int k = 0; k < size[1]; k++) {
            std::vector<Tile*> matches = findMatches(tiles[j][k].getPos());

            if (matches.size() >= 3) return false;
        }

    return true;
}

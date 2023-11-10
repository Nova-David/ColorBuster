
#ifndef TILE_H
#define TILE_H

#include <iostream>
#include <string>

class Tile
{
private:
    int color;
    int type;
    int pos[2];
    bool nullTile;

public:
    Tile();
    Tile(int, int, int*);
    ~Tile();
    std::string toString();
    Tile& operator=(Tile* other);

    void set(int, int, int*);
    int getColor() const;
    void setColor(int);
    int getType() const;
    void setType(int);
    int* getPos();
    void setPos(int*);
    bool isNull();
    void remove();
};

#endif // TILE_H

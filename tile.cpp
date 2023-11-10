
#include "tile.h"
#include <QDebug>

Tile::Tile()
{
    this->color = 0;
    this->type = 0;
    this->pos[0] = 0;
    this->pos[1] = 0;
    this->nullTile = false;
}

Tile::Tile(int color, int type, int pos[2])
{
    this->color = color;
    this->type = type;
    this->pos[0] = pos[0];
    this->pos[1] = pos[1];
    this->nullTile = false;
}

Tile::~Tile() {
//    qDebug() << "Tile deleted!!";
}

void Tile::set(int color, int type, int pos[2])
{
    this->color = color;
    this->type = type;
    this->pos[0] = pos[0];
    this->pos[1] = pos[1];
}

std::string Tile::toString() {
    return "Tile(color: " + std::to_string(color) + ", type: " + std::to_string(type) + ", position: [" + std::to_string(pos[0]) + ", " + std::to_string(pos[1]) + "])";
}

int Tile::getColor() const
{
    return color;
}

void Tile::setColor(int color)
{
    this->color = color;
}

int Tile::getType() const
{
    return type;
}

void Tile::setType(int type)
{
    this->type = type;
}

int* Tile::getPos()
{
    return pos;
}

void Tile::setPos(int pos[2])
{
    this->pos[0] = pos[0];
    this->pos[1] = pos[1];
}

bool Tile::isNull()
{
    return nullTile;
}

void Tile::remove() {
    nullTile = true;
}

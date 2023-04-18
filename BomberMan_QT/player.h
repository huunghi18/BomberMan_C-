
#ifndef PLAYER_H
#define PLAYER_H

#include"iostream"
#include "console.h"
#include <conio.h>
#include "bomb.h"
#include "wall.h"
#include "brick.h"
#include "monster.h"
using namespace std;


class Player
{
private:
    char c;
    time_t timeStart;
    time_t timeEnd;
    Bomb b;
    Wall w;
    Brick br;
    Monster m;
    int check ;

public:
    int x, y, xPre, yPre;
    Player();
    Player(Brick &br, Wall &w, Monster &m);
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
    void calculateMove();
    void putBomb();
    void printHealth();
};

#endif // PLAYER_H

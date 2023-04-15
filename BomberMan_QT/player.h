
#ifndef PLAYER_H
#define PLAYER_H

#include"iostream"
#include "console.h"
#include <conio.h>
#include "bomb.h"
#include "wall.h"
using namespace std;


class player
{
    char c;
    time_t timeStart;
    bomb b;
    wall w;
    int check ;
    int x, y, xPre, yPre;
public:

    player();
    void move();
    void putBomb();
    bool checkWall(int, int);

};

#endif // PLAYER_H

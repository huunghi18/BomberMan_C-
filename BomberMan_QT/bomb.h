#ifndef BOMB_H
#define BOMB_H
#include"iostream"
#include "console.h"
#include <conio.h>
#include <ctime>
#include <wall.h>
using namespace std;
class bomb
{
    wall wB;
    time_t now;
public:
    bomb();
    void createBomb();
    void kickBomb(int, int);
};

#endif // BOMB_H

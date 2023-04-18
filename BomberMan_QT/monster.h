#ifndef MONSTER_H
#define MONSTER_H
#include"iostream"
#include "console.h"
#include <conio.h>
#include <vector>
#include <cstdlib>  // random
#include "wall.h"
#include "brick.h"
using namespace std;

class Monster
{
private:
    Wall w;
    Brick br;
public:
    int arr[8][2];
    Monster();
    void drawMonster();
    bool isMonster(int, int);
};

#endif // MONSTER_H

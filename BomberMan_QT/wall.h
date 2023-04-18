
#ifndef WALL_H
#define WALL_H
#include"iostream"
#include "console.h"
#include <conio.h>
#include <vector>
#include <cstdlib>  // random
using namespace std;

#define CONSOLE_WIDTH 31
#define CONSOLE_HEIGHT 15

class Wall
{
public:

    Wall();
    void drawWall();
    bool isWall(int, int);

};
#endif // WALL_H

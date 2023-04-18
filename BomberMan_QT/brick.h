#ifndef BRICK_H
#define BRICK_H
#include"iostream"
#include "console.h"
#include <conio.h>
#include <vector>
#include <cstdlib>  // random
#include "wall.h"
using namespace std;


class Brick
{
private:
    Wall w;
public:
    int arr[30][2] = {};
    Brick();
    void drawBrick();
    bool isBrick(int, int);
};
#endif // BRICK_H

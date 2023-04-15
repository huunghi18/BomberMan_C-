
#ifndef WALL_H
#define WALL_H
#include"iostream"
#include "console.h"
#include <conio.h>
#include <vector>
#include <cstdlib>  // random
using namespace std;

class wall
{

            vector<vector<int>> v;
public:
    wall();
    void drawWall();
    void fakeWall();
    bool checkWall(int, int);
    bool checkFakeWall(int, int);
};
#endif // WALL_H

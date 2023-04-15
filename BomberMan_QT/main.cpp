#include <iostream>
#include <conio.h>
#include "console.h"
#include "wall.h"
#include "player.h"


using namespace std;

int main()
{
    wall w;
    w.drawWall();

    w.fakeWall();
    player p;
    p.move();
}

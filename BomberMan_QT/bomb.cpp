#include "bomb.h"

bomb::bomb()
{
    now = time(0);

}
void bomb::createBomb() {
    time_t now1 = time(0);
    cout << now1 - now;
//    if(now1 - now > 2) {
//        cout << "E";
//    }
}

void bomb::kickBomb(int x, int y) {

    gotoXY(x,y);
    cout << " ";

    gotoXY(x-1,y);
    if(!wB.checkWall(x-1, y)) {
    cout << " ";
    }
    gotoXY(x+1,y);
    if(!wB.checkWall(x+1, y)) {
    cout << " ";
    }
    gotoXY(x,y-1);
    if(!wB.checkWall(x, y-1)) {
    cout << " ";
    }
    gotoXY(x,y+1);
    if(!wB.checkWall(x, y+1)) {
    cout << " ";
    }
}

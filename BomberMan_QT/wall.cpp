#include "wall.h"

Wall::Wall()
{
}
// create Wall
void Wall::drawWall() {
    for (int x = 1; x <= CONSOLE_WIDTH; x++) {
        gotoXY(x, 1);
        cout << "+" ;
        gotoXY(x, CONSOLE_HEIGHT);
        cout << "+";
    }
    for (int y = 1;y <= CONSOLE_HEIGHT;y++) {
        gotoXY(1, y);
        cout << "+";
        gotoXY(CONSOLE_WIDTH,y);
        cout << "+";
    }
    for (int x = 3; x <= CONSOLE_WIDTH - 2; x+= 2) {
        for(int y = 3; y <= CONSOLE_HEIGHT -2; y+= 2) {
            gotoXY(x, y);
            cout << "+" ;
        }
    }
}
// check tại x, y có phải Wall hay không
bool Wall::isWall (int x, int y) {
    if (y==1 && ( x >= 1 && x <=CONSOLE_WIDTH)) {   // up wall
        return true;
    }
    else if (y==CONSOLE_HEIGHT && ( x >= 1 && x <=CONSOLE_WIDTH)) {  // down wall
        return true;
    }
    else if (x==1 && ( y >= 1 && y <=CONSOLE_HEIGHT)) {  // left wall
        return true;
    }
    else if (x==CONSOLE_WIDTH && ( y >= 1 && y <=CONSOLE_HEIGHT)) {  // right wall
        return true;
    }
    for (int x0 = 3; x0 <= 29; x0+= 2) {
        for(int y0 = 3; y0 <= 13; y0+= 2) {
            if(x == x0 && y == y0) {
                return true;
            }
        }
    }
    return false;
}

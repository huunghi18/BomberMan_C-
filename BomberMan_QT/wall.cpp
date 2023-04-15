#include "wall.h"

wall::wall()
{
}
void wall::drawWall() {
    for (int x = 1; x <= 31; x++) {
        gotoXY(x, 1);
        cout << "+" ;
        gotoXY(x, 15);
        cout << "+";
    }
    for (int y = 1;y <= 15;y++) {
        gotoXY(1, y);
        cout << "+";
        gotoXY(31,y);
        cout << "+";
    }
    for (int x = 3; x <= 29; x+= 2) {
        for(int y = 3; y <= 13; y+= 2) {
        gotoXY(x, y);
        cout << "+" ;
        }
    }
}

    bool wall::checkWall (int x, int y) {
        if (y==1 && ( x >= 1 && x <=31)) {   // up wall
            return true;
        }
        else if (y==15 && ( x >= 1 && x <=31)) {  // down wall
           return true;
        }
        else if (x==1 && ( y >= 1 && y <=15)) {  // left wall
           return true;
        }
        else if (x==31 && ( y >= 1 && y <=31)) {  // right wall
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
    void wall::fakeWall() {
        int xWall, yWall;
        v.resize(10);
        for(int i = 0; i < 10; i++) {
        do {
            xWall = rand()% 30 + 2;
            yWall = rand()% 14 + 2;
        }
        while (checkWall(xWall, yWall));
        v[i].resize(2);
        v.at(i).at(1) = xWall;
        v.at(i).at(2) = yWall;
        gotoXY(xWall,yWall);
        cout <<"H";
        }
    }
    bool wall::checkFakeWall(int x, int y) {
        for(int i = 0; i < 10; i++)  {
            if( (v.at(i).at(1) == x) && (v.at(i).at(2) == y)){
                return true;
            }
        }
        return false;
    }

#include "player.h"


player::player()
{
    x = 6,
    y = 5;
    check = 5;
    xPre = x;
    yPre = y;
    timeStart = time(0);
}




void player::move() {
    while(1) {
        time_t timeEnd = time(0);

    gotoXY(x,y);
    cout << "O";
    xPre = x;
    yPre = y;
    char c;
    if(_kbhit()) {                  // ktra co nhap gia tri tu ban phim khong
        c = _getch();
        if(c == -32)
        {
            c = _getch();
            if( c == 72) {
                y--;
                gotoXY(xPre, yPre);
                cout << " ";
                if(w.checkWall(x,y)) {
                    y++;
                }
            }
            else if( c == 80) {
                y++;
                gotoXY(xPre, yPre);
                cout << " ";
                if(w.checkWall(x,y)) {
                    y--;
                }
            }
            else if( c == 75) {

                x--;
                gotoXY(xPre, yPre);
                cout << " ";
                if(w.checkWall(x,y)) {
                    x++;
                }
            }
            else if( c == 77) {

                x++;
                gotoXY(xPre, yPre);
                cout << " ";
                if(w.checkWall(x,y)) {
                    x--;
                }
            }
        }
        else if( c == 32) {
            c = _getch();
            if(c == -32)
            {
                c = _getch();
                if( c == 72) {
                    gotoXY(xPre, yPre);
                    cout << "X";
                    while(timeEnd - timeStart < 4) {
                        timeEnd = time(0);
                    }
                    timeStart = timeEnd;
                    b.kickBomb(x, y);
                    y--;
                }
                else if( c == 80) {

                    gotoXY(xPre, yPre);
                    cout << "X";
                    while(timeEnd - timeStart < 4) {
                        timeEnd = time(0);
                    }
                    timeStart = timeEnd;
                    b.kickBomb(x, y);
                    y++;
                }
                else if( c == 75) {
                    gotoXY(xPre, yPre);
                    cout << "X";
                    while(timeEnd - timeStart < 4) {
                        timeEnd = time(0);
                    }
                    timeStart = timeEnd;
                    b.kickBomb(x, y);
                    x--;
                }
                else if( c == 77) {

                    gotoXY(xPre, yPre);
                    cout << "X";
                    while(timeEnd - timeStart < 4) {
                        timeEnd = time(0);
                    }
                    timeStart = timeEnd;
                    b.kickBomb(x, y);
                    x++;

                }
            }
        }

        Sleep(50);
    }
    }
}



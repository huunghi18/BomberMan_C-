#include "player.h"

void Player::gameOver() {
    gotoXY(50,17);
    cout << "---GAME OVER--- \t";
    exit(0);
}
// set vị trí ban đầu cho Player
Player::Player()
{
    x = 4,
            y = 3;
    xPre = x;
    yPre = y;
    timeStart = time(0);
    timeEnd = time(0);
}
// set các đối tượng trong Player để check
Player::Player(Brick &br, Wall &w, Monster &m)
{
    x = 4,
            y = 3;
    check = 5;
    xPre = x;
    yPre = y;
    timeStart = time(0);
    this->br = br;
    this->w = w;
    this->m = m;
}
/* di chuyển Player đồng thời check Wall, Brick và Monster
 * Không đi vào vùng có Wall và Monster
 * đi vào vùng có Monster sẽ kết thúc game
 */
void Player::moveUp() {

    if(!w.isWall(x,y-1) && !br.isBrick(x,y-1)) {    // Không được đi qua Wall và Brick
        y--;
        gotoXY(xPre, yPre);
        cout << " ";
        if(m.isMonster(x,y)) {                      // chạm vào Monster thì gameOver
            gameOver();
        }
    }
}
void Player::moveDown() {

    if(!w.isWall(x,y+1) && !br.isBrick(x,y+1)) {
        y++;
        gotoXY(xPre, yPre);
        cout << " ";
        if(m.isMonster(x,y)) {
            gameOver();
        }
    }
}
void Player::moveRight() {

    if(!w.isWall(x+1,y) && !br.isBrick(x+1,y)) {
        x++;
        gotoXY(xPre, yPre);
        cout << " ";
        if(m.isMonster(x,y)) {
            gameOver();
        }
    }
}
void Player::moveLeft() {

    if(!w.isWall(x-1,y) && !br.isBrick(x-1,y)) {
        x--;
        gotoXY(xPre, yPre);
        cout << " ";
        if(m.isMonster(x,y)) {
            gameOver();
        }
    }
}
// Đặt bom
void Player::putBomb() {
    b.setXY(x,y);
    timeEnd = time(0);
    c = _getch();
    if( c == 72) {
        gotoXY(b.getX(),b.getY());
        cout << "0";
        while(timeEnd - timeStart < 4) { // khi nào time >= 4 thì bom nổ
            timeEnd = time(0);
        }
        timeStart = timeEnd; // set lại time sau khi bom nổ
        b.kickBomb(x, y, br, m);
        y--;
    }
    else if( c == 80) {

        gotoXY(b.getX(),b.getY());
        cout << "0";
        while(timeEnd - timeStart < 4) {
            timeEnd = time(0);
        }
        timeStart = timeEnd;
        b.kickBomb(x, y, br, m);
        y++;
    }
    else if( c == 75) {
        gotoXY(b.getX(),b.getY());
        cout << "0";
        while(timeEnd - timeStart < 4) {
            timeEnd = time(0);
        }
        timeStart = timeEnd;
        b.kickBomb(x, y, br, m);
        x--;
    }
    else if( c == 77) {

        gotoXY(b.getX(),b.getY());
        cout << "0";
        while(timeEnd - timeStart < 4) {
            timeEnd = time(0);
        }
        timeStart = timeEnd;
        b.kickBomb(x, y, br, m);
        x++;
    }
}

// Nhận dữ liệu từ bàn phím và in ra Player
void Player::calculateMove() {

    gotoXY(x,y);
    cout << "P";
    xPre = x;
    yPre = y;
    char c;
    if(_kbhit()) {                  // ktra co nhap gia tri tu ban phim khong
        c = _getch();       // đọc dữ liệu từ bộ nhớ đệm
        if(c == -32)        // có tín hiệu từ phim mũi tên
        {
            c = _getch();
            if( c == 72) {   // nhấn phím mũi tên lên
                moveUp();
            }
            else if( c == 80) { // nhấn phím mũi tên xuống
                moveDown();
            }
            else if( c == 75) { // nhấn phím mũi tên qua trái
                moveLeft();
            }
            else if( c == 77) { // nhấn phím mũi tên qua phải
                moveRight();
            }
        }
        else if( c == 32) {
            c = _getch();
            if(c == -32)  // nếu nhấn phím cách
            {
                putBomb(); // đặt bom
            }
        }
    }
}



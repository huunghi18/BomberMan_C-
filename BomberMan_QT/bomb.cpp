#include "bomb.h"
int score = 0; // tính điểm phá tường
Bomb::Bomb()
{
    now = time(0);
}
// in điểm số
void Bomb::printScore() {
    gotoXY(20,17);
    cout << "SCORE: ";
    gotoXY(28,17);
    cout << score;
}
void Bomb::kickBomb(int x, int y, Brick& br, Monster& m) {
    //hien dau X nhung noi bom no
    gotoXY(x,y);
    cout << "X";
    for(int i =0; i < 8; i++) {
        // Kiểm tra có Monster không. nếu có tiêu diệt Monster và đi qua
        if( m.arr[i][0] == x-1 && m.arr[i][1] == y ) {
            m.arr[i][0] = -1;
            m.arr[i][1] = -1;
            score+=20;
        }
    }
    gotoXY(x-1,y);
    if(!m_wB.isWall(x-1, y)) {
        cout << "X";
        // Kiểm tra có Brick không, nếu có phá Brick và đi qua
        if(br.isBrick(x-1,y)) {
            for(int i =0; i < 30; i++) {
                if( br.arr[i][0] == x-1 && br.arr[i][1] == y ) {
                    br.arr[i][0] = -1;
                    br.arr[i][1] = -1;
                    score+=5;
                }
            }

        }
    }
    // Kiểm tra Brick và Monster ở 3 hướng còn lại
    gotoXY(x+1,y);
    if(!m_wB.isWall(x+1, y)) {
        cout << "X";
        for(int i =0; i < 8; i++) {
            if( m.arr[i][0] == x+1 && m.arr[i][1] == y ) {
                m.arr[i][0] = -1;
                m.arr[i][1] = -1;
                score+=20;
            }
        }
        if(br.isBrick(x+1,y)) {
            for(int i =0; i < 30; i++) {
                if( br.arr[i][0] == x+1 && br.arr[i][1] == y ) {
                    br.arr[i][0] = -1;
                    br.arr[i][1] = -1;
                    score+=5;
                }
            }

        }
    }
    gotoXY(x,y-1);
    if(!m_wB.isWall(x, y-1)) {
        cout << "X";
        for(int i =0; i < 8; i++) {
            if( m.arr[i][0] == x && m.arr[i][1] == y-1 ) {
                m.arr[i][0] = -1;
                m.arr[i][1] = -1;
                score+=20;
            }
        }
        if(br.isBrick(x, y-1)) {
            for(int i =0; i < 30; i++) {
                if( br.arr[i][0] == x && br.arr[i][1] == y-1 ) {
                    br.arr[i][0] = -1;
                    br.arr[i][1] = -1;
                    score+=5;
                }
            }

        }
    }
    gotoXY(x,y+1);
    if(!m_wB.isWall(x, y+1)) {
        cout << "X";
        for(int i =0; i < 8; i++) {
            if( m.arr[i][0] == x && m.arr[i][1] == y+1 ) {
                m.arr[i][0] = -1;
                m.arr[i][1] = -1;
                score+=20;
            }
        }
        if(br.isBrick(x, y+1)) {
            for(int i =0; i < 30; i++) {
                if( br.arr[i][0] == x && br.arr[i][1] == y+1 ) {
                    br.arr[i][0] = -1;
                    br.arr[i][1] = -1;
                    score+=5;
                }
            }

        }
    }
    Sleep(500);
    // xoa vung xung quanh bom
    gotoXY(x,y);
    cout << " ";
    gotoXY(x-1,y);
    if(!m_wB.isWall(x-1, y)) {
        cout << " ";
    }
    gotoXY(x+1,y);
    if(!m_wB.isWall(x+1, y)) {
        cout << " ";
    }
    gotoXY(x,y-1);
    if(!m_wB.isWall(x, y-1)) {
        cout << " ";
    }
    gotoXY(x,y+1);
    if(!m_wB.isWall(x, y+1)) {
        cout << " ";
    }
}

#ifndef BOMB_H
#define BOMB_H
#include"iostream"
#include "console.h"
#include <conio.h>
#include <ctime>
#include <wall.h>
#include <brick.h>
#include <monster.h>
using namespace std;

//int score = 0;
class Bomb
{
private:
    int m_x;
    int m_y;
    Wall m_wB;
    time_t now;
public:
    Bomb();
    void createBomb();
    void kickBomb(int, int, Brick&, Monster&);
    void changeArr(Brick &br, int x, int y);
    void setXY(int x, int y) {
        m_x = x;
        m_y = y;
    }
    int getX() {
        return m_x;
    }
    int getY() {
        return m_y;
    }
    void printScore();
};

#endif // BOMB_H

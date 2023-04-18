#include <iostream>
#include <conio.h>
#include "console.h"
#include "wall.h"
#include "player.h"
#include "brick.h"
#include "monster.h"
using namespace std;

int main()
{
    gotoXY(1,20);
    cout << "\t\t---HuongDan: ---\n" ;
    cout << "- P la Player, % la Monster, H la Brick, + la Wall\n";
    cout << "- Bam phim mui ten de dieu khien Player, phim cach de dat bom \n";
    cout << "- Bom se tieu diet Monster va pha Brick, Wall khong the pha \n";
    cout << "- Pha Brick duoc 5 diem, tieu diet Monster duoc 20 diem \n";
    cout << "- Game se ket thuc neu nguoi choi cham vao Monster";
    Wall w;
    Brick br;
    Bomb b;
    Monster m;
    w.drawWall();
    br.drawBrick();
    m.drawMonster();
    Player p (br, w, m);
    while (1) {
        p.calculateMove();
        b.printScore();
    }
}

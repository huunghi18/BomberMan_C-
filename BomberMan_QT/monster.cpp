#include "monster.h"

Monster::Monster()
{
}
// Tạo Monster
void Monster::drawMonster() {
    for(int i = 0; i < 8; i++) { // create 5 Monster
        do {
            arr[i][0] = rand()% (30-2+1) + 2;
            arr[i][1] = rand()% (14-2+1) + 2;
        }
        while (w.isWall(arr[i][0], arr[i][1]) || (arr[i][0] == 4 && arr[i][1] ==3) || br.isBrick(arr[i][0], arr[i][1]));

        gotoXY(arr[i][0],arr[i][1]);
        cout <<"%";
    }
}
// Kiểm tra tại vị trí x, y có phải là Monster hay không
bool Monster::isMonster(int xM, int yM) {
    for(int i =0; i <8 ; i++) {
        if( arr[i][0] == xM && arr[i][1] == yM ) {
            return true;
        }
    }

    return false;
}

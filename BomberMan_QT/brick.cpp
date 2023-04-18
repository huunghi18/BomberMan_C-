#include "brick.h"
Brick::Brick()
{

}
// tạo Brick
void Brick::drawBrick() {
    for(int i = 0; i < 30; i++) { // create 30 Brick
        do {
            arr[i][0] = rand()% (30-2+1) + 2;
            arr[i][1] = rand()% (14-2+1) + 2;
        }
        while (w.isWall(arr[i][0], arr[i][1]) || (arr[i][0] == 4 && arr[i][1] ==3) );

        gotoXY(arr[i][0],arr[i][1]);
        cout <<"H";
    }
}
// Kiểm tra tại vị trí x, y có phải là Brick hay không
bool Brick::isBrick(int xWall, int yWall) {
    for(int i =0; i < 30; i++) {
        if( arr[i][0] == xWall && arr[i][1] == yWall ) {
            return true;
        }
    }

    return false;
}




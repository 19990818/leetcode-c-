#include <math.h>
using namespace std;


class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        auto cnt=[&](int x,int y){
            return pow(x-xCenter,2)+pow(y-yCenter,2)<=pow(radius,2);
        };
        if(xCenter>=x1&&xCenter<=x2&&yCenter>=y1&&yCenter<=y2)return true;
        if(xCenter>=x1&&xCenter<=x2){
            return abs(yCenter-y1)<=radius ||abs(yCenter-y2)<=radius;
        }
        if(yCenter>=y1&&yCenter<=y2){
            return abs(xCenter-x1)<=radius||abs(xCenter-x2)<=radius;
        }
        return cnt(x1,y1)||cnt(x1,y2)||cnt(x2,y2)||cnt(x2,y1);
    }
};
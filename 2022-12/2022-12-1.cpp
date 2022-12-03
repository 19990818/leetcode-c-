#include <vector>
#include <math.h>
using namespace std;


class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int res=-1;
        int des=__INT_MAX__;
        for(int  i=0;i<points.size();i++){
            if(points[i][0]==x||points[i][1]==y){
                int temp=pow(points[i][0]-x,2)+pow(points[i][1]-y,2);
                if(temp<des){
                    des=temp,res=i;
                }
            }
        }
        return res;
    }
};
#include <vector>
#include<math.h>
using namespace std;
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<int> res(2,0);
        int maxSum=0;
        for(int x=0;x<=50;++x){
            for(int y=0;y<=50;++y){
                int temp=0;
                for(vector<int> tower:towers){
                    double dis=pow(x-tower[0],2)+pow(y-tower[1],2);
                    if(dis<=pow(radius,2)){
                        temp+=int(double(tower[2])/double(sqrt(dis)+1));
                    }  
                    
                }
                if(temp>maxSum){
                    maxSum=temp,res[0]=x,res[1]=y;
                }
            }
        }
        return res;
    }
};
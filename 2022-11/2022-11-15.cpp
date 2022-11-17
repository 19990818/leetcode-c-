#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[&](auto &a,auto &b){
            return a[1]>b[1];
        });
        int res=0;
        for(int i=0;i<boxTypes.size();i++){
            if(boxTypes[i][0]<=truckSize){
                truckSize-=boxTypes[i][0];
                res+=boxTypes[i][0]*boxTypes[i][1];
            }else{
                res+=truckSize*boxTypes[i][1];
                truckSize=0;
            }
            if(truckSize==0)return res;
        }
        return res;
    }
};
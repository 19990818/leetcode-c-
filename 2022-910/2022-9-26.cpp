#include <vector>
#include <math.h>
using namespace std;


class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        double n=nums.size()+2;
        double x=n*(n+1)*(2*n+1)/6,y=n*(n+1)/2;
        for(int num:nums){
            x-=num*num;
            y-=num;
        }
        return {int(y+sqrt(2*x-y*y))/2,int(y-sqrt(2*x-y*y))/2};
    }
};
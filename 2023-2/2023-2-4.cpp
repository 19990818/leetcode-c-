#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int start=0,end=0;
        for(auto v:coins){
            if(start+v>end+1){
                break;
            }
            end=end+v;
        }
        return end+1;
    }
};
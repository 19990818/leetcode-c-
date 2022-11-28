#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        for(int o=0;o<n;o++){
            bool flag=true;
            for(int i=1;i<n;i++){
                if(nums[(i+o)%n]<nums[(i-1+o)%n]){
                    flag=false;
                    break;
                }
            }
            if(flag) return true;
        }
        return false;
    }
};
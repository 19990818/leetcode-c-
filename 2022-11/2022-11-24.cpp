#include <vector>
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans=0,pos=-1,temp=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>right) pos=i;
            if(nums[i]>=left) temp=i-pos;
            ans+=temp;
        }
        return ans;
    }
};
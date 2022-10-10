#include <vector>
using namespace std;


class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int dp1=0,dp2=1;
        for(int i=1;i<nums1.size();i++){
            int a=__INT_MAX__,b=__INT_MAX__;
            if(nums1[i]>nums1[i-1]&&nums2[i]>nums2[i-1]){
                a=min(dp1,a),b=min(dp2+1,b);
            }
            if(nums1[i]>nums2[i-1]&&nums2[i]>nums1[i-1]){
                a=min(dp2,a),b=min(dp1+1,b);
            }
            dp1=a,dp2=b;
        }
        return min(dp1,dp2);
    }
};
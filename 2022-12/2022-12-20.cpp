#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
       // 实际上为二分 我们最终的结果必然在[1,max(nums)]中
       int maxNum=0;
       for(int num:nums)maxNum=max(maxNum,num);
       int left=1,right=maxNum;
       while(left<right){
            int mid=((right-left)>>1)+left;
            int cnt=0;
            for(int num:nums){
                cnt+=num/mid;
                if(num%mid==0)cnt--;
            }
            if(cnt<=maxOperations){
                right=mid;
            }else{
                left=mid+1;
            }
       }
       return left;
    }
};
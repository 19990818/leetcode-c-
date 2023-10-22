#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp= vector<vector<int>>(n,vector<int>(2,0));
        dp[0][0]=0,
        dp[0][1]=nums[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=max(dp[i][1],dp[i-1][0]+nums[i]);
            if(i>1){
                dp[i][1]=max(dp[i][1],dp[i-2][1]+nums[i]);
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};


class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int res=0;
        for (int i=low;i<=high;i++){
            string s = to_string(i);
            int temp=0;
            if(s.size()%2==0){
                for(int j=0;j<s.size();j++){
                    int flag=1;
                    if(j>=s.size()/2){
                        flag=-1;
                    }
                    temp+=flag*int(s[j]-'0');
                }
                if(temp==0){
                    res++;
                }
            }
        }
        return res;
    }
};
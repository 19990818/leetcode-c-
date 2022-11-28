#include <vector>
using namespace std;


class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<double>> dp(n,vector<double>(k+1,0));
        vector<int> sum(n+1,0);
        for(int i=0;i<n;i++)sum[i+1]=sum[i]+nums[i];
        for(int i=0;i<n;i++){
            dp[i][1]=double(sum[i+1])/(i+1);
            //cout<<dp[i][1]<<endl;
        }
        //for(auto v:sum) cout<<v<<" ";
        for(int i=0;i<n;i++){
            for(int c=2;c<=k&&c<=i+1;c++){
                for(int j=0;j<i;j++){
                    dp[i][c]=max(dp[i][c],dp[j][c-1]+double(sum[i+1]-sum[j+1])/(i-j));
                }
            }
        }
        return dp[n-1][k];
    }
};
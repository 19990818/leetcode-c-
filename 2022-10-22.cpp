#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n=startTime.size();
        vector<vector<int>> unions(n,vector<int>(3));
        for(int i=0;i<n;i++)
            unions[i]={startTime[i],endTime[i],profit[i]};
        sort(unions.begin(),unions.end(),[&](auto &a,auto &b){
            return a[1]<b[1];
        });
        vector<int> dp(n,0);
        dp[0]=unions[0][2];
        sort(endTime.begin(),endTime.end());
        for(int i=1;i<n;i++){
            if(unions[i][0]>=endTime[i-1]){
                dp[i]=dp[i-1]+unions[i][2];
            }else{
                int j=lower_bound(endTime.begin(),endTime.end(),unions[i][0])-endTime.begin();    
                if(endTime[j]!=unions[i][0]) j--;
                if(j>=0) dp[i]=max(dp[j]+unions[i][2],dp[i-1]);
                else dp[i]=max(unions[i][2],dp[i-1]);
            }
            
        }
        return dp[n-1];
    }
};
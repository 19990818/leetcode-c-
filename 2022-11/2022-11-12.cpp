#include <vector>
using namespace std;
class Solution {
public:
    int numTilings(int n) {
        if(n==1){
            return 1;
        }
        long mod=1e9+7;
        vector<long> dp(n+1,0);
        dp[0]=1,dp[1]=1,dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=(2*dp[i-1]+dp[i-3])%mod;
        }
        return dp[n];
    }
};
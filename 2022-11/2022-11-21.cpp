#include <vector>
using namespace std;


class Solution {
public:
    double soupServings(int n) {
        if(n>5000)return 1;
        if(n%25==0)
            n=n/25;
        else
            n=n/25+1;
        vector<vector<double>> dp(n+1,vector<double>(n+1,0));
        dp[0][0]=0.5;
        for(int i=1;i<n+1;i++){
            dp[i][0]=0,dp[0][i]=1;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                dp[i][j]=(dp[max(i-4,0)][j]+dp[max(i-3,0)][max(j-1,0)]
                +dp[max(i-2,0)][max(j-2,0)]+dp[max(i-1,0)][max(j-3,0)])/4;
            }
        }
        return dp[n][n];
    }
};
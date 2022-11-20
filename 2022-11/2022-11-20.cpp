#include <vector>
using namespace std;
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(query_row+1,vector<double>(query_row+1,0));
        dp[0][0]=poured;
        for(int i=1;i<=query_row;i++){
            for(int j=0;j<i+1;j++){
                if(j==0)dp[i][j]=max(dp[i-1][j]-1,double(0))/2;
                else if(j==i) dp[i][j]=max(dp[i-1][j-1]-1,double(0))/2;
                else dp[i][j]=max(dp[i-1][j]-1,double(0))/2+max(dp[i-1][j-1]-1,double(0))/2;
            }
        }
        return min(dp[query_row][query_glass],double(1));
    }
};
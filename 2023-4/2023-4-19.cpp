#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size()+1,0);
        int n=arr.size();
        dp[n]=0,dp[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            int ma=arr[i];
            for(int j=i;j<n&&j<i+k;j++){
                ma=max(ma,arr[j]);
                dp[i]=max(dp[i],ma*(j-i+1)+dp[j+1]);
            }
        }
        return dp[0];
    }
};



class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n=grid[0].size();
        vector<int> res(n,0);
        for (int j=0;j<n;j++){
            for(int i=0;i<grid.size();i++){
                int cur=to_string(grid[i][j]).size();
                res[j]=max(res[j],cur);
            }
        }
        return res;
    }
};



class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long> res(n,0);
        int ma=0;
        for(int i=0;i<n;i++){
            ma=max(ma,nums[i]);
            nums[i]+=ma;
        }
        res[0]=nums[0];
        for(int i=1;i<n;i++){
            res[i]=long long(res[i-1]+nums[i]);
        }
        return res;
    }
};




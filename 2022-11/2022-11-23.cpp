#include <unordered_map>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int,int> m;
        for(int i=lowLimit;i<=highLimit;i++){
            m[numSum(i)]++;
        }
        int res=0;
        for(auto i=m.begin();i!=m.end();i++){
            res=max(res,i->second);
        }
        return res;
    }
    int numSum(int n){
        int res=0;
        while(n>0){
            res+=n%10,n/=10;
        }
        return res;
    }
};

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        function<int(int,int)> dfs=[&](int i,int j){
            if(i>=m||i<0||j<0||j>=n||grid[i][j]==0)return 0;
            int temp=grid[i][j];
            grid[i][j]=0;
            int res=0;
            res=max(res,temp+dfs(i-1,j));
            res=max(res,temp+dfs(i+1,j));
            res=max(res,temp+dfs(i,j+1));
            res=max(res,temp+dfs(i,j-1));
            grid[i][j]=temp;
            return res;
        };
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    ans=max(ans,dfs(i,j));
                }
            }
        }
        return ans;
    }
};
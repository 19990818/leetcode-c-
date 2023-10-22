#include <vector>
using namespace std;


class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int res=0,m=grid.size(),n=grid[0].size();
        vector<vector<int>> flag(m,vector<int>(n,0));
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0&&flag[i][j]==0&&check(i,j,grid,flag)){
                    res++;
                }
            }
        }
        return res;
    }
    bool check(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &flag){
        vector<vector<int>> q,tos={{-1,0},{0,-1},{1,0},{0,1}};
        q.push_back({i,j});
        int m=grid.size(),n=grid[0].size();
        bool res=true;
        while(q.size()>0){
            auto temp =q;
            q={};
            for(auto v:temp){
                if (v[0]==m-1||v[0]==0||v[1]==n-1||v[1]==0){
                    res=false;
                }
                for (auto to:tos){
                    int x=v[0]+to[0],y=v[1]+to[1];
                    if(x<m&&x>=0&&y<n&&y>=0&&grid[x][y]==0&&flag[x][y]==0){
                        flag[x][y]=1;
                        q.push_back({x,y});
                    }
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int res=0;
        while(mainTank>4&&additionalTank>0){
            res+=50;
            mainTank-=4;
            additionalTank-=1;
        }
        return res+mainTank*10;
    }
};


class Solution {
public:
    int findValueOfPartition(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=__INT_MAX__;
        for(int i=1;i<nums.size();i++){
            res=min(res,nums[i]-nums[i-1]);
        }
        return res;
    }
};

class Solution {
public:
    int mod=1e9+7;
    vector<vector<int>> mem;
    int specialPerm(vector<int>& nums) {
        long res=0;
        int n=1<<nums.size();
        mem=vector(n,vector<int>(nums.size(),-1));
        for(int k=0;k<nums.size();k++){
            res=(res+dfs((n-1)^(1<<k),k,nums))%mod;
        }
        return int(res);
    }
    int dfs(int i,int j,vector<int>& nums){
        if(i==0){
            return 1;
        }
        if(mem[i][j]!=-1){
            return mem[i][j];
        }
        long res=0;
        for(int k=0;k<nums.size();k++){
            if(i>>k&1>0&&(nums[k]%nums[j]==0||nums[j]%nums[k]==0)){
                res=(res+dfs(i^(1<<k),k,nums))%mod;
            }
        }
        mem[i][j]=int(res);
        return int(res);
    }
};
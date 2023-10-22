#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()-1]*k+k*(k-1)/2;
    }
};


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int> ma,mb;
        vector<int> res(A.size(),0);
        auto cnt=[&](){
            int ans=0;
            for(auto k:ma){
                if(mb[k.first]==1){
                    ans++;
                }
            }
            return ans;
        };
        for(int i=0;i<A.size();i++){
            ma[A[i]]=1,mb[B[i]]=1;
            res[i]=cnt();
        }
        return res;
    }
};


class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int res=0,m=grid.size(),n=grid[0].size();
        unordered_map<int,int> travel;
        auto check=[&](int i,int j){
            return i>=0&&i<m&&j>=0&&j<n&&grid[i][j]>0&&travel[i*n+j]==0;
        };
        auto bfs=[&](int i,int j){
            vector<vector<int>> q={{i,j}},tos={{-1,0},{1,0},{0,-1},{0,1}};
            int ans=0;
            while(q.size()>0){
                vector<vector<int>> temp=q;
                q={};
                for(int i=0;i<temp.size();i++){
                    ans+=grid[temp[i][0]][temp[i][1]];
                    for(auto to:tos){
                        int curx=temp[i][0]+to[0],cury=temp[i][1]+to[1];
                        if(check(curx,cury)){
                            travel[curx*n+cury]=1;
                            q.push_back({curx,cury});
                        }
                    }
                }
            }
            return ans;
        };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0&&travel[i*n+j]==0){
                    travel[i*n+j]=1;
                    res=max(res,bfs(i,j));
                }
            }
        }
        return res;
    }
};
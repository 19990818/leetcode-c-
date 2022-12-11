#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums) {
        int res=0;
        int cur=nums[0];
        for(int i=1;i<nums.size();++i){
            if(nums[i]<cur+1){
                ++cur;
                res+=cur-nums[i];
            }else{
                cur=nums[i];
            }
        }
        return res;
    }
};


class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int res=0;
        for(auto v:strs){
            if(isNum(v)){
                res=max(res,atoi(v.c_str()));
            }else{
                int l=v.size();
                res=max(res,l);
            }
        }
        return res;
    }
    bool isNum(string s){
        for(auto c:s){
            if(!isdigit(c)){
                return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int n=vals.size();
        vector<vector<int>> g(n);
        for(auto edge:edges){
            g[edge[0]].push_back(vals[edge[1]]);
            g[edge[1]].push_back(vals[edge[0]]);
        }
        for(int i=0;i<n;++i){
            sort(g[i].begin(),g[i].end());
        }
        int res=INT32_MIN;
        for(int i=0;i<n;++i){
            int temp=vals[i];
            res=max(res,temp);
            for(int j=0;j<k&&j<g[i].size();++j){
                temp+=g[i][g[i].size()-1-j];
                res=max(res,temp);
            }
        }
        return res;
    }
};



class Solution {
public:
    int maxJump(vector<int>& stones) {
        return max(getMaxDistancve(stones,1),getMaxDistancve(stones,2));
    }
    int getMaxDistancve(vector<int>& stones,int i){
        int res=0;
        int start=stones[0],end=stones[stones.size()-1];
        for(;i<stones.size();i+=2){
            res=max(res,stones[i]-start);
            start=stones[i];
        }
        res=max(res,end-start);
        return res;
    }
};


class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<grid.size();++i){
            sort(grid[i].begin(),grid[i].end());
        }
        for(int j=0;j<grid[0].size();++j){
            int temp=0;
            for(int i=0;i<grid.size();++i){
                temp=max(temp,grid[i][j]);
            }
            res+=temp;
        }
        return res;
    }
};



class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int res=-1;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> m,travel;
        for(int i=0;i<nums.size();++i){
            m[nums[i]]=1;
        }
        for(int v:nums){
            if(travel[v]==0){
                int cur=v,cnt=1;
                while((long long)(cur)*(long long)(cur)<INT_MAX&&m[cur*cur]==1){
                    cur=cur*cur;
                    travel[cur]=1;
                    cnt++;
                }
                if(cnt>=2&&cnt>res)res=cnt;
            }
        }
        return res;
    }
};
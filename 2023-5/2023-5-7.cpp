#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
       vector<int> res=dfs(n,cost,1);
       return res[0];
    };
    vector<int> dfs(int n,vector<int>& cost,int i){
        if(2*i>=n) return {0,cost[i-1]};
        vector<int> res1=dfs(n,cost,2*i);
        vector<int> res2=dfs(n,cost,2*i+1);
        return {res1[0]+res2[0]+abs(res1[1]-res2[1]),max(res1[1],res2[1])+cost[i-1]};
    }
};


class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> res(queries.size(),0);
        vector<int> t(n,0);
        t[queries[0][0]]=queries[0][1];
        for(int i=1;i<queries.size();i++){
            int idx=queries[i][0],v=queries[i][1];
            res[i]=res[i-1];
            if(idx>0){
                if(t[idx]!=0&&t[idx]==t[idx-1]){
                    res[i]--;
                }
                if(t[idx-1]==v){
                    res[i]++;
                }
            }
            if(idx<n-1){
                if(t[idx]!=0&&t[idx]==t[idx+1]){
                    res[i]--;
                }
                if(t[idx+1]==v){
                    res[i]++;
                }
            }
            t[idx]=v;
        }
        return res;
    }   
};


class FrequencyTracker {
public:
    unordered_map<int,int> m,cnt;
    FrequencyTracker() {

    }
    
    void add(int number) {
        m[number]++;
        cnt[m[number]]++;
        cnt[m[number]-1]--;
    }
    
    void deleteOne(int number) {
        if(m[number]<=0) return;
        m[number]--;
        cnt[m[number]]++;
        cnt[m[number]+1]--;
    }
    
    bool hasFrequency(int frequency) {
        return cnt[frequency]>0;
    }
};


class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        unordered_map<int,int> m,m2;
        for(auto v:nums){
            m[v]++;
        }
        for(int i=0;i<nums.size();i++){
            m2[nums[i]]++;
            m[nums[i]]--;
            if(m[nums[i]]==0){
                m.erase(nums[i]);
            }
            res[i]=m2.size()-m.size();
        }
        return res;
    }
};

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        if(cnts(player1)>cnts(player2)){
            return 1;
        }
        if(cnts(player1)==cnts(player2)){
            return 0;
        }
        return 2;
    }
    int cnts(vector<int>& player){
        int s=0;
        for(int i=0;i<player.size();i++){
            if((i>0&&player[i-1]==10)||(i>1&&player[i-2]==10)){
                s+=player[i]*2;
            }else{
                s+=player[i];
            }
        }
        return s;
    }
};
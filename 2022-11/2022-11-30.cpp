#include <stack>
#include <vector>
#include <unordered_map>
using namespace std;
class FreqStack {
public:
    unordered_map<int,int> cnt;
    vector<vector<int>> s;
    FreqStack() {

    }
    
    void push(int val) {
        if(cnt[val]==s.size()){
            s.push_back({val});
        }else{
            s[cnt[val]].push_back(val);
        }
        cnt[val]++;
    }
    
    int pop() {
        int res=s[s.size()-1][s[s.size()-1].size()-1];
        s[s.size()-1].pop_back();
        if(s[s.size()-1].size()==0){
            s.pop_back();
        }
        cnt[res]--;
        return res;
    }
};

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3,0);
        vector<int> show(3,0);
        show[0]=1;
        int res=0;
        for(int num:nums){
            int o=num%3;
            vector<int> temp=dp;
            for(int i=0;i<3;i++){
                if(show[(i-o+3)%3]==1){
                    dp[i]=max(dp[i],temp[(i-o+3)%3]+num);
                }
            }
            show[o]=1;
            for(int j=0;j<3;j++){
                if(dp[j]>0) show[j]=1;
            }
            res=max(res,dp[0]);
        }
        return res;
    }
};
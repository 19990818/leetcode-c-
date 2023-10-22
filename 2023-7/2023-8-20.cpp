#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
#include <algorithm>
using namespace std;




class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]<target){
                    res++;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0,j=0;
        while(i<str1.length()&&j<str2.length()){
            int t=str2[j]-str1[i];
            if(t==0||t==1||(str1[i]=='z'&&str2[j]=='a')){
                j++;
            }
            i++;
        }
        return j>=str2.length();
    }
};



class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int res=nums.size(),n=nums.size();
        vector<vector<int>> cnts=vector<vector<int>>(n+1,vector<int>(3,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<3;j++){
                cnts[i+1][j]=cnts[i][j];
            }
            cnts[i+1][nums[i]-1]++;
        }
        for(int i=0;i<=n;i++){
            for(int j=i;j<=n;j++){
                int cnt1=i-cnts[i][0];
                int cnt2=j-i-cnts[j][1]+cnts[i][1];
                int cnt3=n-j-cnts[n][2]+cnts[j][2];
                res=min(res,cnt1+cnt2+cnt3);
            }
        }
        return res;
    }
};


class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        string res="";
        for(string word:words){
            res+=word[0];
        }
        return res==s;
    }
};



class Solution {
public:
    int minimumSum(int n, int k) {
        int cnt=0;
        int res=0;
        unordered_map<int,int> m;
        for(int i=1;cnt<n;i++){
            if (i<k&&m[k-i]==1){
                continue;
            }
            res+=i;
            m[i]=1;
            cnt++;
        }
        return res;
    }
};



class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end(),[&](vector<int> o1,vector<int> o2){
            return o1[1]<o2[1];
        });
        vector<int> dp=vector<int>(n+1,0);
        int k=0;
        for(int i=0;i<n;i++){
            dp[i+1]=dp[i];
            while(k<offers.size()&&i==offers[k][1]){
                dp[i+1]=max(dp[i+1],dp[offers[k][0]]+offers[k][2]);
            }
        }
        return dp[n];
    }
};

#include <string>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;


class Solution {
public:
    int minimumOperations(string num) {
        vector<bool> flag=vector<bool>(2,false);
        int n=num.size();
        for(int i=n-1;i>=0;i--){
            int v=int(num[i]-'0');
            switch (v)
            {
            case 0:
            case 5:
                if (flag[0])
                    return n-i-2;
                flag[v/5]=true;
                break;
            case 2:
            case 7:
                if (flag[1]) return n-i-2;
                break;
            }
        }
        if(flag[0]) return n-1;
        return n;
    }
};


class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long res=0;
        long long sum=0;
        unordered_map<long long,long long> cnt;
        cnt[0]=1;
        for(int x: nums){
            if(x%modulo==k){
                sum+=1;
            }
            res+=cnt[(sum-k+modulo)%modulo];
            cnt[(sum%modulo)]+=1;
        }
        return res;
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> t1=copyRange(0,nums.size()-1,nums);
        vector<int> t2=copyRange(1,nums.size(),nums);
        return max(robHelp(t1),robHelp(t2));
    }
    int robHelp(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        vector<vector<int>> dp= vector<vector<int>>(n,vector<int>(2,0));
        dp[0][0]=0,
        dp[0][1]=nums[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=max(dp[i][1],dp[i-1][0]+nums[i]);
            if(i>1){
                dp[i][1]=max(dp[i][1],dp[i-2][1]+nums[i]);
            }
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
    vector<int> copyRange(int start,int end,vector<int>& src){
        vector<int> res=vector<int>(end-start,0);
        for(int i=start;i<end;i++){
            res[i-start]=src[i];
        }
        return res;
    }
};


class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=0;
        for(char c:s){
            if(c=='1'){
                ones++;
            }
        }
        string res="";
        for(int i=0;i<ones-1;i++){
            res+="1";
        }
        for(int i=ones-1;i<s.size()-1;i++){
            res+="0";
        }
        res+="1";
        return res;
    }
};


class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        long long res=0;
        int n=maxHeights.size();
        for(int i=0;i<n;i++){
            long long temp=0;
            int cur=maxHeights[i];
            for(int j=i;j>=0;j--){
                cur=min(cur,maxHeights[j]);
                cur+=temp;
            }
            cur=maxHeights[i];
            for(int j=i;j<n;j++){
                cur=min(cur,maxHeights[j]);
                cur+=temp;
            }
            res=max(res,temp);
        }
        return res;
    }
};
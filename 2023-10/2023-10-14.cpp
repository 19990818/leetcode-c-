#include <vector>
#include <unordered_map>
#include <vector>
#include <math.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            res^=nums[i];
        }
        return res;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int res=0;
        int cnt=0;
        for(int i=nums.size()-1;i>=0&&cnt<k;i--){
            if (nums[i]<=k && m[nums[i]]==0){
                m[nums[i]]=1;
                cnt++;
            }
            res++;
        }
        return res;
    }
};


class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int num:nums){
            m[num]++;
        }      
        int res=0;
        for(auto k:m){
            if(k.second<2){
                return -1;
            }
            res+=(k.second+2)/3;
        }
        return res;
    }
};


class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int res=0,sum=0xfffff;
        for(int num:nums){
            sum&=num;
            if(sum==0){
                res+=1;
                sum=0xfffff;
            }
        }      
        return max(res,1);
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> res=vector<int>(32,0);
        auto deal =[&](int num,vector<int>& res){
            if(num<0){
                res[31]+=1;
                num+=0x80000000;
            }
            for(int i=30;i>=0;i--){
                if(num>=1<<i){
                    num-=1<<i;
                    res[i]+=1;
                }
            }
        };
        for(int num:nums){
            deal(num,res);
        }
        int ans=0;
        for(int i=30;i>=0;i--){
            if(res[i]%3!=0){
                ans+=1<<i;
            }
        }
        if(res[31]%3!=0){
            ans-=0x80000000;
        }
        return ans;
    }
};


class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    res=max(res,(long long)(nums[i]-nums[j])*nums[k]);
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long res=0;
        int n=nums.size();
        vector<int> pre=vector<int>(n,0);
        vector<int> suf=vector<int>(n,0);
        pre[0],suf[n-1]=0,0;
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],nums[i-1]);
        }       
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],nums[i+1]);
        }
        for(int i=0;i<n;i++){
            res=max(res,(long long)(pre[i]-nums[i])*suf[i]);
        }
        return res;
    }
};
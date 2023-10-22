#include <vector>
#include <string>
using namespace std;



class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int res=0;
        auto gcd =[&](int a,int b){
            while(b>0){
                int t=b;
                b=a%b;
                a=t;
            }
            return a;
        };    
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(gcd(int(to_string(nums[i])[0]-'0'),nums[j]%10)==1){
                    res++;
                }
            }
        }
        return res;
    }
};



class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        long t1=num1,t2=num2;
        for(int i=1;t1>0;i++){
            t1-=t2;
            if(__builtin_popcountll(t1)<=i&&t1>=i){
                return i;
            }
        }
        return -1;
    }
};


class Solution {
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        long res=1,mod=1e9+7;
        bool flag=false;
        int cnt=0;
        for(int num:nums){
            if(num==1){
                if(flag){
                    res=(res*cnt)%mod;
                }
                cnt=1;
                flag=true;
            }else{
                cnt++;
            }
        }
        if(flag){
            return res;
        }
        return 0;
    }
};


class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int cnt=0,res=0,start=0;
        bool flag=false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0&&nums[i]<=threshold){
                if((i-start)%2==0){
                    cnt++;
                }else{
                    start=i;
                    cnt=1;
                }
                flag=true;
            }else if(nums[i]<=threshold&&(i-start)%2==1&&flag){
                cnt++;
            }else{
                flag=false;
                cnt=0;
            }
            res=max(res,cnt);
        }      
        return res;
    }
};
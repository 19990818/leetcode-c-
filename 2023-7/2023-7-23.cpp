#include <vector>
#include <math.h>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int mv=0,idx=0;
        for(int i=0;i<height.size();i++){
            if(height[i]>mv){
                mv=height[i];
                idx=i;
            }
        }
        auto getSum=[&](int start,int step){
            if (start==idx)return 0;
            int temp=height[start],cidx=start;
            int ans=0;
            for(int i=start+step;i<height.size()&&i>=0;i+=step){
                if(height[i]>=temp){
                    ans+=temp*(abs(cidx-i)-1);
                    temp=height[i];
                    cidx=i;
                }else{
                    ans-=height[i];
                }
                if(i==idx)break;
            }
            return ans;
        };
        return getSum(0,1)+getSum(height.size()-1,-1);
    }
};



class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int v:nums){
            m[v]++;
        }
        int nmc=nums[0],cnt=m[nums[0]];
        for(auto k:m){
            if(k.second>cnt){
                cnt=k.second,nmc=k.first;
            }
        }
        cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==nmc){
                cnt++;
            }
            if(2*cnt>(i+1)&&2*(m[nmc]-cnt)>nums.size()-1-i){
                return i;
            }
        }
        return -1;
    }
};


class Solution {
public:
    bool isGood(vector<int>& nums) {
        if(nums.size()<2){
            return false;
        }
        unordered_map<int,int> m;
        for(int num:nums){
            m[num]++;
        }
        for(int i=1;i<nums.size();i++){
            if(i<nums.size()-1&&m[i]==1){
                continue;
            }
            if(i==nums.size()-1&&m[i]==2){
                continue;
            }
            return false;
        }
        return true;
    }
};



class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long res=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            if(res>=nums[i]){
                res+=nums[i];
            }else{
                res=nums[i];
            }
        }
        return res;
    }
};
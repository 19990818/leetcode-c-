#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        unordered_map<int,int> m;
        int preSum=0;
        m[preSum]=0;
        for(int i=0;i<nums.size();++i){
            preSum=preSum+nums[i];
            m[preSum]=i+1;
        }
        int res=-1;
        if(preSum<x){
            return res;
        }
        preSum=0;
        for(int i=0;i<=nums.size();++i){
            if(m.find(x-preSum)!=m.end()){
                if (res==-1){
                    res=m[x-preSum]+i;
                }else{
                    res=min(res,m[x-preSum]+i);
                }
            }
            if (i<nums.size()){
                preSum=preSum+nums[nums.size()-i-1];
            }   
        }
        return res;
    }
};
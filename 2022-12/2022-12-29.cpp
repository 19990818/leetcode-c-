#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int,int> m;
        for(int num:nums1) m[num]|=1;
        for(int num:nums2) m[num]|=2;
        for(int num:nums3)m[num]|=4;
        vector<int> res;
        for(auto it:m){
            if(it.second==1||it.second==2||it.second==4){
                continue;
            }
            res.push_back(it.first);
        }
        return res;
    }
};



class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        auto check=[&](int d){
            int cnt=1,x0=price[0];
            for(int x:price){
                if(x>=x0+d){
                    x0=x;
                    cnt++;
                }
            }
            return cnt>=k;
        };
        int left=0,right=price[price.size()-1]-price[0]+1;
        while(left+1<right){
            int mid=(long)(right+left)>>1;
            if(check(mid))left=mid;
            else right=mid;
        }   
        return left;
    }
};
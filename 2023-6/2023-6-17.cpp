#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<long> a(nums.size(),0);
        for (int i=0;i<nums.size(); i++) {
            if (s[i]=='R') {
                a[i]= long(nums[i]+d);
            }else{
                a[i]=long(nums[i]-d);
            }
        }
        sort(a.begin(),a.end());
        long res=0;
        long mod = 1e9+7;
        for (int i=0;i<a.size();i++){
            res=(res+i*a[i]-sum)%mod;
            sum=(sum+a[i])%mod;
        }
        return int(res);
    }
};


class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        int t=prices[0]+prices[1];
        if(t>money){
            return money;
        }
        return money-t;
    }
};
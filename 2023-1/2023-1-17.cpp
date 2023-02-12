#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int mod=1e9+7;
        unordered_map<long,int> m;
        auto rev=[&](int a){
            long res=0;
            while(a>0){
                res=res*10+a%10;
                a/=10;
            }
            return res;
        };
        for(auto num:nums){
          m[long(num-rev(num))]++;  
        }
        int res=0;
        for(auto i:m){
            res=(res+((long long)i.second*(i.second-1))/2)%mod;
        }
        return res;
    }
};
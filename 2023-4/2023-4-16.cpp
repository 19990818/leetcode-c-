#include <vector>
using namespace std;



class Solution {
public:
    int diagonalPrime(vector<vector<int>>& nums) {
        int res=0;
        auto isPrime=[&](int a){
            if(a==1) return false;
            for(int i=2;i*i<=a;i++){
                if(a%i==0){
                    return false;
                }
            }
            return true;
        };
        for(int i=0;i<nums.size();++i){
            for(int j=0;j<nums[i].size();j++){
                if(i==j||j==nums.size()-i-1){
                    if(isPrime(nums[i][j])){
                        res=max(res,nums[i][j]);
                    }
                }
            }
        }
        return res;
    }
};
#include <vector>
using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int i=0,j=0;
        while(i<groups.size()&&j<nums.size()){
            int temp=j;
            for(int k=0;k<groups[i].size();++k){
                if(groups[i][k]==nums[j]){
                    j++;
                }
            }
            if((j-temp)!=groups[i].size()){
                j=temp+1;
            }else{
                i++;
            }
        }
        return i==groups.size();
    }
};
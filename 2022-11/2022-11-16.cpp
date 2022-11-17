#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        unordered_map<int,int> pos;
        for(int i=0;i<nums.size();i++){
            pos[nums[i]]=i;
        }
        int cur=pos[0];
        for(int i=1;i<nums.size();i++){
            if(cur-pos[i]>1)return false;
            cur=max(cur,pos[i]);
        }
        return true;
    }
};
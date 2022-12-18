#include <vector>
#include <math.h>
using namespace std;


class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum=0;
        for(int num:nums)sum+=num;
        return ceil(abs(sum-goal)/(double)limit);
    }
};


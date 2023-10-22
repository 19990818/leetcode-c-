#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> q;
        long long res = 0;
        for (int num:nums) {
            q.push(num);
        }
        for(int i=0;i<k;i++){
            int cur = q.top();
            q.pop();
            q.push((cur+2)/3);
            res += (long long) cur;
        }
        return res;
    }
};

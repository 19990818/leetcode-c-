#include <vector>
#include <functional>
using namespace std;


class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int n=toppingCosts.size();
        int res=baseCosts[0];
        function<void(int,int)> dfs=[&](int cur,int idx){
            res=getClosetNum(res,cur,target);
            if(idx==n||cur>target){
                return;
            }
            dfs(cur,idx+1);
            dfs(cur+toppingCosts[idx],idx+1);
            dfs(cur+toppingCosts[idx]*2,idx+1);
        };
        for(int v:baseCosts){
            dfs(v,0);
        }
        return res;
    }
    int getClosetNum(int a,int b,int t){
        if(abs(a-t)<abs(b-t))return a;
        if(abs(a-t)==abs(b-t))return min(a,b);
        return b;
    }
};
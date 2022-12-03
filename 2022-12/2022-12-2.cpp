#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> pre=getCost(boxes);
        reverse(boxes.begin(),boxes.end());
        // cout<<boxes<<endl;
        vector<int> post=getCost(boxes);
        vector<int> res(boxes.size(),0);
        for(int i=1;i<pre.size();i++){
            res[i-1]=pre[i]+post[pre.size()-i];
        }
        return res;
    }
    vector<int> getCost(string s){
        int sum=0;
        vector<int> dp(s.size()+1,0);
        for(int i=0;i<s.size();i++){
            dp[i+1]=dp[i]+sum;
            if(s[i]=='1')sum++;
        }
        return dp;
    }
};
#include<vector>
#include <string>
#include <functional>
using namespace std;


class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        function<void(int)> dfs=[&](int i){
            if(i==s.size()){
                res.push_back(s);
                return;
            }
            if(isupper(s[i])){
                s[i]=tolower(s[i]);
                dfs(i+1);
                s[i]=toupper(s[i]);
            }else if(islower(s[i])){
                s[i]=toupper(s[i]);
                dfs(i+1);
                s[i]=tolower(s[i]);
            }
            dfs(i+1);
        };
        dfs(0);
        return res;
    }
};


class Solution {
public:
    int magicalString(int n) {
        vector<int> ans(n,0);
        if(n==1) return 1;
        int res=0,j=0;
        int cur=1;
        for(int i=0;i<n;){
            int count=ans[j];
            if(ans[j]==0){
                count=cur;
            }
            for(;i<n&&count>0;){
                ans[i]=cur;
                i++;
                if(cur==1){
                    res++;
                }
                count--;
            }
            cur^=3;
            j++;
        }
        return res;
    }
};
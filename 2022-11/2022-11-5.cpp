#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool parseBoolExpr(string expression) {
        if(expression=="t") return true;
        if(expression=="f") return false;
        vector<string> exps=splitExpr(expression.substr(2,expression.size()-3));
        bool res=parseBoolExpr(exps[0]);
        if(expression[0]=='|'){
            for(int i=1;i<exps.size();++i)
                res=res||parseBoolExpr(exps[i]);
            return res;
        }
        if(expression[0]=='&'){
            for(int i=1;i<exps.size();++i)
                res=res&&parseBoolExpr(exps[i]);
            return res;
        }
        return !res;
    }
    vector<string> splitExpr(string exp){
        exp+=',';
        int cnt=0;
        string temp="";
        vector<string> ans;
        for(int i=0;i<exp.size();i++){
            if(exp[i]=='(') cnt++;
            else if(exp[i]==')')cnt--;
            else if(exp[i]==','&&cnt==0){
                ans.push_back(temp),temp="";
                continue;
            }
            temp+=exp[i];
        }
        return ans;
    }
};


class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        vector<int> sum(n+1,0);
        for(int i=n-1;i>=0;i--) sum[i]=sum[i+1]+piles[i];
        for(int j=1;j<n+1;j++) dp[n][j]=0,dp[n-1][j]=piles[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=n;j++){
                for(int x=0;i+x<n;x++){
                    if(1<=x&&x<=j)
                        dp[i][j]=max(dp[i][j],sum[i]-dp[i+x][j]);
                    else if (j<x&&x<=2*j)
                        dp[i][j]=max(dp[i][j],sum[i]-dp[i+x][x]);
                }
            }
        }
        return dp[0][1];
    }
};


class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> arrx={1},arry={1};
        vector<int> res;
        unordered_map<int,int> m;
        if(x>1) arrx=getSmallerBound(x,bound);
        if(y>1) arry=getSmallerBound(y,bound);
        for(int x:arrx){
            for(int y:arry){
                if(m[x+y]==0&&x+y<=bound){
                    m[x+y]=1,res.push_back(x+y);
                }
            }
        }
        return res;
    }
    vector<int> getSmallerBound(int t,int bound){
        vector<int> res;
        int temp=1;
        while(temp<=bound){
            res.push_back(temp),temp*=t;
        }
        return res;
    }
};
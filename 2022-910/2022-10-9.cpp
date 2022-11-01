#include <string>
#include <sstream>
#include<iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<string> a;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')a.push(s.substr(i,1));
            else{
                int temp=1,in=0;
                for(;a.top()!=")";){
                    stringstream ss;
                    ss<<a.top();
                    int part;
                    ss>>part;
                    in+=part,a.pop();
                }
                if(in!=0) temp=2*in;
                a.pop(),a.push(to_string(temp));
            }
        }
        int res=0;
        for(;!a.empty();){
            stringstream ss;
            ss<<a.top();
            int part;
            ss>>part;
            res+=part,a.pop();
        }
        return res;
    }
};



class Solution {
public:
    int commonFactors(int a, int b) {
        int ans=0;
        for(int i=1;i<=min(a,b);i++){
            if(a%i==0&&b%i==0)ans++;
        }
        return ans;
    }
};


class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                int temp=grid[i][j];
                vector<vector<int>> tos={{-1,-1},{-1,0},{-1,1},{1,-1},{1,0},{1,1}};
                for(vector<int> to:tos) temp+=grid[i+to[0]][j+to[1]];
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};


class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt=0;
        for(int i=31;i>=0;i--) if(num2&1<<i) cnt++;
        vector<int> a(32,0);
        for(int i=31;i>=0&&cnt>0;i--){
            if (num1&1<<i) a[i]=1,cnt--; 
        }
        for(int i=0;i<32&&cnt>0;i++){
            if(a[i]==0) a[i]=1,cnt--;
        }
        int ans=0;
        for(int i=0;i<32;i++) if(a[i]==1)ans+=1<<i;
        return ans;
    }
};
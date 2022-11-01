#include <string>
#include<vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2)return true;
        vector<int> diff;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]) diff.push_back(i);
        }
        if(diff.size()!=2) return false;
        return s1[diff[0]]==s2[diff[1]]&&s1[diff[1]]==s2[diff[0]];
    }
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int> m;
        for(int num:nums) m[num]=1;
        int flag=0,ans=0;
        for(;head!=nullptr;head=head->next){
            if(m[head->val]==1&&flag==0){
                ans++,flag=1;
            }else if(m[head->val]==0){
                flag=0;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int ans=logs[0][0],temp=logs[0][1];
        for(int i=1;i<logs.size();i++){
            if(logs[i][1]-logs[i-1][1]>temp){
                temp=logs[i][1]-logs[i-1][1],ans=logs[i][0];
            }else if(logs[i][1]-logs[i-1][1]==temp){
                ans=min(ans,logs[i][0]);
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ans(pref.size(),0);
        ans[0]=pref[0];
        for(int i=1;i<pref.size();++i){
            ans[i]=pref[i-1]^pref[i];
        }
        return ans;
    }
};


class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(k,0)));
        dp[1][0][0]=1;
        int mod=1e9+7;
        for(int i=1;i<m+1;++i){
            for(int j=1;j<n+1;++j){
                for(int x=0;x<k;++x){
                    dp[i][j][(x+grid[i-1][j-1])%k]=(dp[i][j][(x+grid[i-1][j-1])%k]+dp[i-1][j][x]+dp[i][j-1][x])%mod;
                }
            }
        }
        return dp[m][n][0];
    }
};


class Solution {
public:
    string robotWithString(string s) {
        vector<int> digits(26,0),smaller(26,0);
        for(int i=0;i<s.size();++i) digits[int(s[i]-'a')]++;
        for(int i=1;i<26;i++) smaller[i]=smaller[i-1]+digits[i-1];
        stack<char> st;
        string ans="";
        for(int i=0;i<s.size();++i){
            st.push(s[i]);
            for(int j=int(s[i]-'a')+1;j<26;j++) smaller[j]--;
            while(!st.empty()&&smaller[int(st.top()-'a')]<=0){
                ans+=st.top();
                st.pop();
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int temp=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i;j<arr.size();j++){
                if(arr[j]<arr[i]) temp=max(temp,j);
            }
            if(i==temp){
                ans++;
                temp++;
            }
        }
        return ans;
    }
};
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <functional>
using namespace std;


class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int i=0;
        for(;i<word1.size()&&i<word2.size();i++){
            ans+=word1[i];
            ans+=word2[i];
        }
        ans+=word1.substr(i);
        ans+=word2.substr(i);
        return ans;
    }
};


class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> a(nums.size()),b(nums.size());
        a[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            a[i]=max(a[i-1],nums[i]);
        }
        b[nums.size()-1]=nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            b[i]=min(b[i+1],nums[i]);
        }
        for(int i=0;i<nums.size()-1;i++){
            if(a[i]<=b[i+1]){
                return i+1;
            }
        }
        return -1;
    }
};


class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int,int> a,b;
        for(vector<int> trip:trips){
            a[trip[1]]+=trip[0],b[trip[2]]+=trip[0];
        }
        int sum=0;
        for(int i=0;i<1001;i++){
            sum=sum+a[i]-b[i];
            if(sum>capacity) return false;
        }
        return true;
    }
};


class Solution {
public:
    string crackSafe(int n, int k) {
        int highest=pow(10,n-1);
        unordered_map<int,int> m;
        string ans="";
        function<void(int)> dfs= [&](int node){
            for(int i=0;i<k;i++){
                if(m[node*10+i]==0){
                    m[node*10+i]=1;
                    dfs((node*10+i)%highest);
                    ans+=i+'0';
                }
            }
        }
        dfs(0);
        ans+=string(n-1,'0')
    }  
};
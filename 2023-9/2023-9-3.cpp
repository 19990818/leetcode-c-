#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int> t=vector<int>(n,0);
        for(int i=0;i<n;i++){
            t[i]=(dist[i]-1)/speed[i]+1;
        }
        sort(t.begin(),t.end());
        for(int i=0;i<n;i++){
            if(t[i]<i+1){
                return i;
            }
        }
        return n;
    }
};


class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=0;i<s1.size();i++){
            int flag=i>1?-1:1;
            if(s1[i]==s2[i]||(s1[i+2*flag]==s2[i]&&s1[i]==s2[i+2*flag])){
                continue;
            }
            return false;
        }
        return true;
    }
};


class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<char> os1,os2,es1,es2;
        for(int i=0;i<s1.length();i++){
            if(i%2==0){
                os1.push_back(s1[i]);
                os2.push_back(s2[i]);
            }else{
                es1.push_back(s1[i]);
                es2.push_back(s2[i]);
            }
        }
        sort(os1.begin(),os1.end());
        sort(os2.begin(),os2.end());
        sort(es1.begin(),es1.end());
        sort(es2.begin(),es2.end());
        return join(os1)==join(os2)&&join(es1)==join(es2);   
    }
    string join(vector<char> &a){
        string res="";
        for(char c:a){
            res+=c;
        }
        return res;
    }
};


class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long res=0;
        long long sum=0;
        unordered_map<int,int> ma;
        for(int i=0;i<k;i++){
            sum+=nums[i];
            ma[nums[i]]++;
        } 
        if(ma.size()>=m){
            res=sum;
        }  
        for(int i=k;i<nums.size();i++){
            sum=sum-nums[i-k]+nums[i];
            ma[nums[i-k]]--;
            ma[nums[i]]++;
            if(ma[nums[i-k]]==0){
                ma.erase(nums[i-k]);
            }
            if(ma.size()>=m){
                res=max(res,sum);
            }
        }
        return res;
    }
};
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        bool bulky = isBulky(length,width,height);
        if(mass>=100&&bulky){
            return "Both";
        }
        if(mass>=100&&!bulky){
            return "Heavy";
        }
        if(bulky){
            return "Bulky";
        }
        return "Neither";
    }
    bool isBulky(int length,int width,int height) {
        return length>=1e4||width>=1e4||height>=1e4||(long long)length*width*height>=1e9;
    }
};


class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long res=0;
        vector<int> parent=vector<int>(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto v:edges){
            merge(v[0],v[1],parent);
        }
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[find(i,parent)]++;
        }
        for(int i=0;i<n;i++){
            res+=(long long)(n-m[i])*m[i];
        }
        return res/2;
    }
    int find(int a,vector<int>& parent){
        if(a==parent[a]){
            return a;
        }
        parent[a]=find(parent[a],parent);
        return parent[a];
    }
    void merge(int a,int b,vector<int>& parent){
        a=find(a,parent);
        b=find(b,parent);
        parent[a]=b;
    }
};


class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long sum = 0;
        for(int num:nums){
            sum+=num;
        }
        int n=nums.size();
        int c=target/sum,part=target%sum;
        if(part==0){
            return c*n;
        }
        bool flag=false;
        int minCnt=n;
        long prefix=0;
        unordered_map<int,int> m;
        m[0]=-1;
        for(int i=0;i<2*n;i++){
            prefix+=nums[i%n];
            m[prefix]=i;
            if(m[prefix-part]!=0){
                minCnt=min(minCnt,i-m[prefix-part]);
                flag=true;
            }
        }
        if(flag){
            return c*n+minCnt;
        }
        return -1;
    }
};


class Solution {
public:
    int differenceOfSums(int n, int m) {
        int cntm=n/m;
        int end=cntm*m;
        return n*(n+1)/2-(end+m)*cntm;
    }
};

class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        int n=s1.size();
        vector<int> diff;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                diff.push_back(i);
            }
        }      
        if(diff.size()%2!=0){
            return -1;
        }
        int pair=diff.size()/2;
        vector<int> dp = vector<int>(pair+1,0);
        for(int i=1;i<=pair;i++){
            dp[i]=1e5;            
            for(int j=0;j<i;j++){
                dp[i]=min(dp[i],dp[j]+min(cnt1(diff,x,j,i),cnt2(diff,x,j,i)));
            }
        }
        return dp[pair];
    }
    int cnt1(vector<int>& diff,int x, int start,int end){
        int res=0;
        for(int i=2*start;i<2*end;i+=2){
            res+=min(x,diff[i+1]-diff[i]);
        }
        return res;
    } 
    int cnt2(vector<int>& diff,int x,int start,int end){
        int res=0;
        for(int i=2*start+1;i<2*end-1;i+=2){
            res+=min(x,diff[i+1]-diff[i]);
        }
        res+=min(x,diff[2*end-1]-diff[start]);
        return res;
    }
};
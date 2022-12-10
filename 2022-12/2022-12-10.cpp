#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        function<bool(vector<int>,vector<int>)> less=[&](vector<int> a,vector<int> b){
            if(a[2]>b[2])return true;
            if(a[2]<b[2])return false;
            if(a[1]>b[1])return true;
            if(a[1]<b[1])return false;
            return a[0]>=b[0];
        };
        for(int i=0;i<cuboids.size();++i){
            sort(cuboids[i].begin(),cuboids[i].end());
        }
        sort(cuboids.begin(),cuboids.end(),less);
        const int n=cuboids.size();
        vector<int> dp(n,0);
        int res=0;
        for(int i=0;i<n;++i){
            dp[i]=cuboids[i][2];
            for(int j=0;j<i;j++){
                if(cuboids[i][1]<=cuboids[j][1]&&cuboids[i][0]<=cuboids[j][0]){
                    dp[i]=max(dp[i],dp[j]+cuboids[i][2]);
                }
            }
            res=max(res,dp[i]);
        }
        return res;
    } 
};


class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xors(arr.size()+1,0);
        for(int i=0;i<arr.size();++i){
            xors[i+1]=xors[i]^arr[i];
        }
        vector<int> res(queries.size(),0);
        for(int i=0;i<queries.size();++i){
            res[i]=xors[queries[i][0]]^xors[queries[i][1]+1];
        }
        return res;
    }
};


class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        unordered_map<int,int> m;
        int n=arr.size();
        function<bool(int)> canNext=[&](int cur){
            return cur<n&&cur>=0&&m[cur]==0;
        };
        vector<int> q={start};
        while(q.size()>0){
            auto temp=q;
            q={};
            while(temp.size()>0){
                int cur=temp[temp.size()-1];
                temp.pop_back();
                if(arr[cur]==0) return true;
                if(canNext(cur+arr[cur])){
                    q.push_back(cur+arr[cur]);
                    m[cur+arr[cur]]=1;
                }
                if(canNext(cur-arr[cur])){
                    q.push_back(cur-arr[cur]);
                    m[cur-arr[cur]]=1;
                }
            }
        }
        return false;
    }
};


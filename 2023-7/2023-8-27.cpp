#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()<2){
            return intervals;
        }
        sort(intervals.begin(),intervals.end(),[&](vector<int> o1,vector<int> o2){
            return o1[0]<o2[0];
        });
        int start=intervals[0][0],end=intervals[0][1];
        vector<vector<int>> res;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=end){
                start=min(start,intervals[i][0]);
                end=max(end,intervals[i][1]);
            }else{
                res.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
            if(i==intervals.size()-1){
                res.push_back({start,end});
            }
        }
        return res;
    }
};


class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int left=0,right=0;
        for(char c:moves){
            if(c=='R'){
                left--;
                right++;
            }else if(c=='L'){
                left++;
                right--;
            }else{
                left++;
                right++;
            }
        }
        return max(left,right);
    }
};


class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long res=0;
        int cnt=0;
        unordered_map<int,int> m;
        for(int i=1;cnt<n;i++){
            if(m[target-i]==0){
                res+=i;
                cnt++;
                m[i]=1;
            }
        }
        return res;
    }
};
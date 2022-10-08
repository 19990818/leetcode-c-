#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> cnt(26,0);
        for(int i=0;i<word.size();i++)
            cnt[int(word[i]-'a')]++;
        vector<int> noZero;
        for(int num:cnt){
            if(num>0) noZero.push_back(num);
        }
        if(noZero.size()==1) return true;
        sort(noZero.begin(),noZero.end());
        return (noZero[0]==1&&noZero[1]==noZero[noZero.size()-1]) ||
         (noZero[0]==noZero[noZero.size()-2]&&noZero[noZero.size()-1]-1==noZero[0]);
    }
};



class LUPrefix {
public:
    int cur=0;
    unordered_map<int,int> m;
    LUPrefix(int n) {

    }
    
    void upload(int video) {
        m[video]=1;
        int temp=cur+1;
        for(;m[temp]!=0;temp++);
        cur=temp-1;
    }
    
    int longest() {
        return cur;
    }
};


class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        if(nums1.size()%2==1){
            for(int num:nums2) ans^=num;
        }
        if(nums2.size()%2==1){
            for(int num:nums1) ans^=num;
        }
        return ans;
    }
};
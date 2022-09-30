#include<string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if(s1.size()!=s2.size()) return false;
        s1=s1+s1;
        return s1.find(s2)!=string::npos;
    }
};


class RLEIterator {
public:
    vector<int> arr,cnt;
    int p=0;
    RLEIterator(vector<int>& encoding) {
        for(int i=0;i<encoding.size();i+=2){
            arr.push_back(encoding[i+1]);
            cnt.push_back(encoding[i]);
        }
    }
    
    int next(int n) {
        int ans=-1;
        while(n>0&&cnt.size()>p){
            if(cnt[p]>=n){
                ans=arr[p];
                cnt[p]-=n;
                n=0;
            }else{
                n-=cnt[p];
                cnt[p]=0;
            }
            if(cnt[p]==0) p++;
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
       sort(nums1.begin(),nums1.end());
       vector<pair<int,int>> num2;
        for(int i=0;i<nums2.size();i++){
            num2.push_back(make_pair(nums2[i],i));
        }
        // function<bool(int,int)>less=[&](int i,int j){
        //     return i<j;
        // };
        vector<int> ans(nums1.size(),-1);
        //sort(nums1.begin(),nums1.end(),less);
        sort(num2.begin(),num2.end());

        int i=nums1.size()-1,j=nums1.size()-1;
        for (;i>=0;){
            for (;i>=0&&nums1[j]<=num2[i].first;){
                --i;
            }
            if(i<0)break;
            ans[num2[i].second]=nums1[j];
            --i,--j;
        }
        for(int k=0;k<nums1.size();k++){
            if(ans[k]==-1){
                ans[k]=nums1[j];
                j--;
            }
        }
        return ans;
    }
};
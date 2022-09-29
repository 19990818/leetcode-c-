#include<string>
#include <vector>
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

    }
};
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<int> g,preSum(1,0);
        for(int i=0;i<nums.size();++i){
            if(nums[i]==1){
                g.push_back(i-g.size());
                preSum.push_back(preSum[preSum.size()-1]+g[g.size()-1]);
            }
        }
        int res=__INT_MAX__;
        int m=g.size();
        for(int i=0;i<m-k+1;++i){
            int mid=i+k/2;
            int r=g[mid];
            int f=r*(1-k%2)+preSum[k+i]-preSum[mid+1]+preSum[i]-preSum[mid];
            res=min(res,f);
        }
        return res;
    }
};


class Solution {
public:
    int similarPairs(vector<string>& words) {
        int res=0;
        for(int i=0;i<words.size();++i){
            for(int j=i+1;j<words.size();++j){
                if(isSimlar(words[i],words[j])){
                    res++;
                }
            }
        }
        return res;
    }
    bool isSimlar(string a,string b){
        vector<int> letters1(26,0),letters2(26,0);
        for(char c:a){
            if(letters1[int(c-'a')]==0){
                letters1[int(c-'a')]+=1;
            }
        }
        for(char c:b){
            if(letters2[int(c-'a')]==0){
                letters2[int(c-'a')]+=1;
            }
        }
        for(int i=0;i<letters1.size();++i){
            if(letters1[i]!=letters2[i])return false;
        }
        return true;
    }
};


class Solution {
public:
    int smallestValue(int n) {
        while(true){
            int s=n,t=0;
            for(int i=2;i*i<=s;i++){
                while(n%i==0){
                    t+=i;
                    n=n/i;
                }
            }
            if(n>1){
                t+=n;
            }
            if(t==s)return t;
            n=t;
        }
    }
};
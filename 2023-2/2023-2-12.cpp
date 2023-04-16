#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;


class Solution {
public:
    string alphabetBoardPath(string target) {
        string res="";
        int startx=0,starty=0;
        for(char c:target){
            int x=int(c-'a')/5,y=int(c-'a')%5;
            if(c=='z'){
                res+=repeat("R",(y-starty))+repeat("L",starty-y)+repeat("D",x-startx)+repeat("U",startx-x);
            }else{
                res+=repeat("D",x-startx)+repeat("U",startx-x)+repeat("R",(y-starty))+repeat("L",starty-y);
            }
            startx=x,starty=y;
            res+="!";
        }
        return res;
    }
    string repeat(string a,int k){
        string ans="";
        if(k<0){
            return ans;
        }
        for(int i=0;i<k;++i){
            ans+=a;
        }
        return ans;
    }
};

class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long res=0;
        int n=nums.size()-1;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt+1<=n){
                cnt+=2;
                res+=append(nums[i],nums[n-i]);
            }else if(cnt==n){
                cnt+=1;
                res+=nums[i];
            }
        }
        return res;
    }
    long long append(int a,int b){
         string temp=to_string(a)+to_string(b);
         long long res=0;
         int n=temp.size()-1;
         for(int i=temp.size()-1;i>=0;i--){
            res+=(long long)pow(10,i)*(long long)(temp[n-i]-'0');
         }
         return res;
    }
};


class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long res=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            auto l=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
            auto r=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);
            res+=(long long)(r-l);
        }
        return res;
    }
};
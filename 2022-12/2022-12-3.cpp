#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    int secondHighest(string s) {
        unordered_map<int,int> m;
        for(char c:s){
            if(isdigit(c)){
                m[int(c-'0')]=1;
            }
        }
        int temp=0;
        for(int i=9;i>=0;i--){
            if(m[i]==1){
                temp++;
                if(temp==2){
                    return i;
                }
            }
        }
        return -1;
    }
};


class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int x=tomatoSlices/2-cheeseSlices,y=2*cheeseSlices-tomatoSlices/2;
        if(tomatoSlices%2==0&&x>=0&&y>=0){
            return {x,y};
        }
        return {};
    }
};


class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for(int i=to_string(low).size();i<=to_string(high).size();++i){
            vector<int> ans=getStaAndDis(i);
            int s=ans[0],d=ans[1];
            for(int j=0;j<10-i;++j){
                if(s<=high&&s>=low){
                    res.push_back(s);
                }
                s+=d;
            }
        }
        return res;
    }
    vector<int> getStaAndDis(int l){
        int s=0,d=0;
        for(int i=1;i<=l;++i){
            s=10*s+i,d=10*d+1;
        }
        return {s,d};
    }
};

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        sort(nums.begin(),nums.end());
        for(int num:nums){
            m[num]++;
        }
        for(int num:nums){
            if(m[num]!=0){
                for(int j=0;j<k;j++){
                    if(m[num+j]==0)return false;
                    m[num+j]--;
                }
            }
        }
        return true;
    }
};
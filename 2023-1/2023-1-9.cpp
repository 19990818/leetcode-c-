#include <vector>
#include <string>
#include <unordered_map>
using namespace std;



class Solution {
public:
    int reinitializePermutation(int n) {
        int start=n-2;
        int cur=start,cnt=0;
        while(cur!=start||cnt==0){
            if(cur%2==0){
                cur=cur/2;
            }else{
                cur=n/2+(cur-1)/2;
            }
            cnt++;
        }
        return cnt;
    }
};


class Solution {
public:
    bool digitCount(string num) {
        unordered_map<int,int> m;
        for(auto c:num){
            m[int(c-'0')]++;
        }
        for(int i=0;i<num.size();i++){
            if(m[i]!=int(num[i]-'0')){
                return false;
            }
        }
        return true;
    }
};
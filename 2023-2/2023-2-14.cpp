#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res=0,cnt=0;
        unordered_map<int,int> m;
        for(int i=0;i<hours.size();++i){
            if(hours[i]>8)cnt++;
            else cnt--;
            if(m[cnt]==0)m[cnt]=i+1;
            if(cnt>0) res=max(res,i+1);
            else if(m[cnt-1]!=0) res=max(res,i+1-m[cnt-1]);
        }
        return res;
    }
};
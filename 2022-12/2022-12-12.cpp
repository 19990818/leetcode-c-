#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int res=0;
        for(int i=0;i<s.size();++i){
            vector<int> cnt(26,0);
            int mx=0;
            for(int j=i;j<s.size();++j){
                cnt[int(s[j]-'a')]++;
                mx=max(mx,cnt[int(s[j]-'a')]);
                int mi=1000;
                for(int k=0;k<26;k++){
                    if(cnt[k]>0&&cnt[k]<mi) mi=cnt[k];
                }
                res+=mx-mi;
            }
        }
        return res;
    }
};
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int distinctSubseqII(string s) {
        vector<int> cnt(26,0);
        int mod=1e9+7;
        for (char c:s){
            int temp=1;
            for(int i=0;i<26;i++){
                temp=(temp+cnt[i])%mod;
            }
            cnt[int(c-'a')]=temp;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+cnt[i])%mod;
        }
        return ans;
    }  
};
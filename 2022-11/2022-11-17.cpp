#include <string>
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for(int i=0;i<s.size();i++)
            pos[s[i]-'a'].push_back(i);
        ;
        int res=0;
        for(auto word:words){
            int cur=-1;
            bool ok=true;
            for(auto c:word){
                auto &temp=pos[c-'a'];
                auto it=upper_bound(temp.begin(),temp.end(),cur);
                if(it==temp.end()){
                    ok=false;
                    break;
                }
                cur=*it;
            }
            if(ok)res++;
        }
        return res;
    }
};
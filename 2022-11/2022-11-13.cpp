#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> m;
        for(int i=0;i<order.size();i++){
            m[order[i]]=i;
        }
        sort(s.begin(),s.end(),[&](char a,char b){
            return m[a]<m[b];
        });
        return s;
    }
};
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int> m;
        for(char c:allowed)m[c]=1;
        int flag=1,res=0;
        for(string word:words){
            int flag=1;
            for(char c:word){
                if(m[c]==0){
                    flag=0;
                    break;
                }
            }
            res+=flag;
        }
        return res;
    }
};
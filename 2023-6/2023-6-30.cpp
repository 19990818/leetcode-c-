#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string,int> m;
        int res=0;
        for(auto word:words){
            string temp="";       
            for(char c:word){
                temp=c+temp;
            }
            if(m[temp]==1){
                res+=1;
            }
            m[word]=1;
        }
        return res;
    }
};

class Solution {
public:
    int longestString(int x, int y, int z) {
        return 4*min(x,y)+2*z+2*min(min(z,1),abs(x-y));
    }
};
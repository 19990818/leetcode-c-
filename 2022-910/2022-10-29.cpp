#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        unordered_map<string,int> m={{"type",0},{"color",1},{"name",2}};
        int ans=0;
        for(vector<string> item:items){
            if(item[m[ruleKey]]==ruleValue) ans++;
        }
        return ans;
    }
};
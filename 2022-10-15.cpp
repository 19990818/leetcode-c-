#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int pos=0;
        vector<string> ans;
        for(int i=1;i<=n;i++){
            if (pos<target.size()){
                ans.push_back("Push");
            }
            if(pos<target.size()&&target[pos]!=i){
                ans.push_back("Pop");
            }else{
                pos++;
            }
        }
        return ans;
    }
};
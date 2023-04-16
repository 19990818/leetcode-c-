#include <vector>
#include <algorithm>
using namespace std;


#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<int> diff(reward1.size(),0);
        int res=0;
        for(int i=0;i<reward1.size();i++){
            res+=reward2[i];
            diff[i]=reward1[i]-reward2[i];
        }
        sort(diff.begin(),diff.end());
        for(int i=reward1.size()-1;i>=0&&i>=(reward1.size()-k);i--){
            res+=diff[i];
        }
        return res;
    }
};
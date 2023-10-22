#include <vector>
using namespace std;

const int mx = int(1e6);
vector<int> primes;
vector<bool> np(mx+1,false);
int init = [](){
    for (int i=2;i<=mx;i++){
        if(!np[i]){
            primes.push_back(i);
            for(int j=i;j<=mx/i;j++){
                np[i*j]=true;
            }
        }
    }
    return 0;
}();
class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> res;
        for(int x:primes){
            if(x>n-x){
                break;
            }
            if(!np[n-x]){
                res.push_back({x,n-x});
            }
        }
        return res;
    }
};
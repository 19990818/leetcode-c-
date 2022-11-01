



#include <vector>
#include <unordered_map>
using namespace std;



class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> m;
        int i=0,j=0;
        int ans=0;
        for(;i<=j&&j<fruits.size();){
            while(true){
                //cout<<"test"<<endl;
                m[fruits[j]]++,j++;
                if(m.size()>2) break;
                if(j==fruits.size()) j++;break;
            }
            //cout<<j<<i<<endl;
            ans=max(j-i-1,ans);
            //cout<<ans<<endl;
            while(m.size()>2){
                m[fruits[i]]--;
                if(m[fruits[i]]==0) m.erase(fruits[i]);
                i++;
            }
        }
        return ans;
    }
};
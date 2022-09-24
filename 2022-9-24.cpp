#include <vector>
using namespace std;

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> ans(n);
        if (k==0){
            return ans;
        }
        int origin=0;
        if(k>0){
            int i=1;
             for (int cnt=0;cnt<k;cnt++){
                origin+=code[i];
                i=(i+1)%n;              
             }
             ans[0]=origin;
             for (int j=1;j<n;j++){
                ans[j]=ans[j-1]+code[i]-code[j];
                i=(i+1)%n;
             }
        }else{
            int i=n-1;
            for (int cnt=0;cnt<-k;cnt++){
                origin+=code[i];
                i=(i-1+n)%n;
            }
            ans[0]=origin;
            for (int j=1;j<n;j++){
                 //cout<<i<<" "<<j<<endl;
                 i=(i+1)%n;
                ans[j]=ans[j-1]+code[j-1]-code[i];
                
            }
        }
        return ans;
    }
};
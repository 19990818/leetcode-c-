#include <string>
using namespace std;
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int ans=0;
        for(int i=1;i<sequence.size()/word.size()+1;i++){
            string temp="";
            for(int j=0;j<i;j++){
                temp+=word;
            }
            if(sequence.find(temp)!=string::npos){
                ans=i;
            }
        }
        return ans;
    }
};
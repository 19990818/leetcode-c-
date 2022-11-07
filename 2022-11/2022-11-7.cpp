#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        unordered_map<string,int> m;
        vector<string> res;
        for(int i=2;i<s.size()-1;i++){
            if(isValid(s.substr(1,i-1))&&isValid(s.substr(i,s.size()-i-1))){
                string temp=s.substr(0,i) + ", "+s.substr(i);
                res.push_back(temp);
            }
            for(int j=1;j<=i;j++){
                for(int k=i;k<s.size()-1;k++){
                    string left=s.substr(1,j-1)+"."+s.substr(j,i-j);
                    string right=s.substr(i,k-i)+"."+s.substr(k,s.size()-1-k);
                    string temp;
                    if(isValid(left)&&isValid(right))
                        temp="("+left+", "+right+")";
                    else if(isValid(left)&&isValid(s.substr(i,s.size()-i-1)))
                        temp="("+left+", "+s.substr(i,s.size()-i-1)+")";
                    else if (isValid(right)&&isValid(s.substr(1,i-1)))
                        temp="("+s.substr(1,i-1)+", "+right+")";
                    if(m[temp]==0&&temp!=""){
                        m[temp]=1;
                        res.push_back(temp);
                    }
                }
            }
        }
        return res;
    }
    bool isValid(string s){
        if(s==""||s==".") return false;
        int pos=s.find(".");
        if(pos==string::npos){
            if(s[0]=='0'&&s.size()>1)return false;
            return true;
        }
        if(pos==0||(pos>1&&s[0]=='0'))return false;
        if(pos==s.size()-1||(pos<s.size()-1)&&s[s.size()-1]=='0')return false;
        return true;
    }
};
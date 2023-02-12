#include <vector>
#include <string>
#include <unordered_map>
using namespace std;



class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> m;
        for(auto v:knowledge)m[v[0]]=v[1];
        bool in=false;
        string res="";
        string temp="";
        for(char c:s){
            if(c=='('){
                in=true;
            }else if(c==')'){
                in=false;
                if(m[temp]==""){
                    res+="?";
                }else{
                    res+=m[temp];
                }
            }else if(in){
                temp+=c;
            }else{
                res+=c;
            }
        }
        return res;
    }
};
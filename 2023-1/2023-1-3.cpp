#include <string>
using namespace std;

class Solution {
public:
    bool areNumbersAscending(string s) {
        string temp="";
        int now=0;
        s+=" a";
        for(char c:s){
            if(isdigit(c)){
                temp+=c;
            }else{
                if(temp!=""){
                    if(atoi(temp.c_str())<=now){
                        return false;
                    }
                    now=atoi(temp.c_str());
                    temp="";
                }
            }
        }
        return true;
    }
};
#include <string>
using namespace std;


class Solution {
public:
    string interpret(string command) {
        string res;
        for(int i=0;i<command.size();i++){
            if(command[i]=='G') res+=command[i];
            else if (command[i]=='('&&command[i+1]==')'){
                res+='o';
                i++;
            }else{
                res+="al";
                i+=3;
            }
        }
        return res;
    }
};
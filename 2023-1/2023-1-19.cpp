#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        bool cond1=password.size()>=8;
        unordered_map<char,int> m;
        for(char c:"!@#$%^&*()-+"){
            m[c]=1;
        }
        bool cond2=false,cond3=false,cond4=-false,cond5=false,cond6=true;
        for(char c:password){
            if(c>='0'&&c<='9')cond2=true;
            if(c>='a'&&c<='z')cond3=true;
            if(c>='A'&&c<='Z')cond4=true;
            if(m[c]==1) cond5=true;
        }
        for(int i=1;i<password.size();++i){
            if(password[i]==password[i-1]){
                cond6=false;
                break;
            }
        }
        // cout<<cond1<<cond2<<cond3<<cond4<<cond5<<cond6<<endl;
        return cond1&&cond2&&cond3&&cond4&&cond5&&cond6;
    }
};
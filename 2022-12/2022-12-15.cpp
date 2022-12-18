#include <string>
using namespace std;


class Solution {
public:
    int getLucky(string s, int k) {
        string res=letterToNum(s);
        for(int i=0;i<k;++i){
            res=getSumStr(res);
        }
        return atoi(res.c_str());
    }
    string letterToNum(string s){
        string res="";
        for(char c:s){
            res+=to_string(int(c-'a'+1));
        }
        return res;
    }
    string getSumStr(string s){
        int res=0;
        for(char c:s){
            res+=c-'0';
        }
        return to_string(res);
    }
};
#include <string>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_map<string,int> m;
        word+="a";
        int flag=0,res=0;
        string temp="";
        for(auto c:word){
            if(isdigit(c)){
                temp+=c;
                flag=1;
            }else{
                if(m[trim0(temp)]==0&&flag==1){
                    m[trim0(temp)]=1;
                    res++;
                }
                temp="",flag=0;
            }
        }
        return res;
    }
    string trim0(string word){
        if(word.size()<2){
            return word;
        }
        // cout<<word<<endl;
        int idx=word.size()-1;
        for(int i=0;i<word.size();i++){
            if(word[i]!='0'){
                idx=i;
                break;
            }
        }
        return word.substr(idx);
    }
};
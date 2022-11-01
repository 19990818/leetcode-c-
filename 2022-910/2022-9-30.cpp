#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int> m1,m2;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0) m1[i]=0,m2[j]=0;
            }
        }
        for(unordered_map<int, int>::iterator it=m1.begin();it!=m1.end();it++){
            for(int j=0;j<matrix[0].size();j++){
                matrix[it->first][j]=0;
            }
        }
        for (unordered_map<int,int>::iterator it=m2.begin();it!=m2.end();it++){
            for(int i=0;i<matrix.size();i++) matrix[i][it->first]=0;
        }
    }
};


class Solution {
public:
    string reformatNumber(string number) {
        string temp="";
        for(char c:number){
            if(c>='0'&&c<='9') temp+=c;
        }
        number=temp;
        string ans="";
        for(int i=0;i<number.size();i+=3){
            if(ans!="") ans+="-";
            if (number.size()-i>4) ans+=number.substr(i,3);
            else if(number.size()-i==4){
                ans+=number.substr(i,2);
                ans+="-";
                ans+=number.substr(i+2,2);
                break;
            }else{
                ans+=number.substr(i);
            }
        }
        return ans;
    }
};
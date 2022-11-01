#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]=i+1;
        }
        for(int i=0;i<pieces.size();++i){
            if (m[pieces[i][0]]==0){
                return false;
            }
            for (int j=1;j<pieces[i].size();++j){
                if (pieces[i][j-1]+1!=pieces[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    int countSubstrings(string s, string t) {     
        int ans=0;
        vector<vector<int>> same(s.length()+1,vector<int>(t.length()+1,0)),diff(s.length()+1,vector<int>(t.length()+1,0));
        for (int i=0;i<s.length();i++){
            for (int j=0;j<t.length();j++){
                if (s[i]==t[j]){
                    same[i+1][j+1]=same[i][j]+1;
                    diff[i+1][j+1]=diff[i][j];
                }else{
                    diff[i+1][j+1]=same[i][j]+1;
                }
                ans+=diff[i+1][j+1];
            }
        }
        return ans;
    }
    
};
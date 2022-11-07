
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string res1,res2;
        for(string word:word1){
            res1+=word;
        }
        for(string word:word2){
            res2+=word;
        }
        return res1==res2;
    }
};
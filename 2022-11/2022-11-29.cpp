#include <string>
using namespace std;

class Solution {
public:
    int minOperations(string s) {
        int res1=0,res2=0;
        char temp1='0',temp2='1';
        for(char c:s){
            if(c==temp1){
                res2++;
            }else{
                res1++;
            }
            swap(temp1,temp2);
        }
        return min(res1,res2);
    }
};
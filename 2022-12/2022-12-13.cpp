#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> m;
        for(char c:sentence){
            m[c]=1;
        }
        return m.size()==26;
    }
};
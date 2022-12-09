#include <string>
using namespace std;



class Solution {
public:
    bool squareIsWhite(string coordinates) {
        return (int(coordinates[0]-'a')+int(coordinates[1]))%2==0;
    }
};
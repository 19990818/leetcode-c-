
#include <math.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int res1,res2;
        for(int i=1;;++i){
            int temp=(i*i+i)/2,temp2=(i+1)*(i+2)/2;
            if(temp>=target){
                if ((temp-target)%2==0) return i;
                if ((temp2-target)%2==0) return i+1;
                return i+2;
            }
        }
        return -1;
    }
};
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
#include <algorithm>
#include <map>
#include <functional>
using namespace std;

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        int ans=0;
        string nstr=to_string(n);
        for(int i=1;i<nstr.size();i++) ans+=pow(double(digits.size()),double(i));
        map<string,int> m;
        map<string,int> less;
        int start=0;
        for(int i=0;i<digits.size();i++) {
            m[digits[i]]=i;
            stringstream ss;
            ss<<digits[i];
            int end;
            ss>>end;
            for(int j=start+1;j<=end;j++) less[to_string(j)]=i,start=end;
        }
        for(int j=start+1;j<=9;j++) less[to_string(j)]=digits.size();
        for(int i=0;i<nstr.size();i++){
            bool ok;
            if(i>0) ok=(m.find(nstr.substr(i-1,1))!=m.end());
            if(i!=0&&!ok)break;
            ans+=less[nstr.substr(i,1)]*pow(double(digits.size()),double(nstr.size()-i-1));
        }
        cout<<ans<<endl;
        function<bool()> isExistSame=[&](){
            for(int i=0;i<nstr.size();i++){
                if(m.find(nstr.substr(i,1))==m.end()){
                    return false;
                }
            }
            return true;
        };
        if(isExistSame()) return ans+1;
        return ans;
    }
};
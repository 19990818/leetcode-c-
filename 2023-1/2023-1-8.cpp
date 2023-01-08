#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for(string word:words){
            if(word.size()>=pref.size()&&word.substr(0,pref.size())==pref){
                ans++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {  
        int kind=0;
        const int bulky=1,heavy=2;
        if(isHeavy(mass))kind|=heavy;
        if(isBulky(length,width,height))kind|=bulky;
        string res="";
        // cout<<kind<<endl;
        switch (kind)
        {
        case 0:
            res="Neither";
            break;
        case 1:
            res="Bulky";
            break;
        case 2:
            res="Heavy";
            break;
        default:
            res="Both";
            break;
        }
        return res;
    }
    bool isBulky(int length,int width,int height){
        const int maxV=1e9,maxS=1e4;
        long long v=(long long)length*width*height;
        return v>=maxV||(length>=maxS||width>=maxS||height>=maxS);
    }
    bool isHeavy(int height){
        return height>=100;
    }
};


class DataStream {
public:
    int cnt=0,target=0,v=0;
    DataStream(int value, int k) {
        target=k;
        v=value;
    }
    
    bool consec(int num) {
        if(num==v){
            cnt++;
        }else{
            cnt=0;
        }
        return cnt>=target;
    }
};

class Solution {
public:
    int xorBeauty(vector<int>& nums) {
        int res=0;
        for(int num:nums){
            res^=num;
        }
        return res;
    }
};

class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n=stations.size();
        vector<long long> sum(n+1,0);
        for(int i=0;i<n;++i){
            sum[i+1]=(long long)sum[i]+stations[i];
        }
        vector<long long> part(n,0);
        long long mn=INT64_MAX;
        for(int i=0;i<n;++i){
            part[i]=sum[min(i+r+1,n)]-sum[max(0,i-r)];
            mn=min(mn,part[i]);
        }
        auto check=[&](long long mid){
            long long need=0,sumD=0;
            vector<long long> diff(n,0);
            for(int i=0;i<n;i++){
                sumD+=diff[i];
                long long m=mid-part[i]-sumD;
                if(m>0){
                    need+=m;
                    sumD+=m;
                    if(need>k)return false;
                    if(i+2*r+1<n) diff[i+2*r+1]-=m;
                }
            }
            return true;
        };
        long long left=mn,right=mn+k+1;
        while(left+1<right){
            long long mid=(left+right)/2;
            if(check(mid))left=mid;
            else right=mid;
        }
        return left;
    }
};
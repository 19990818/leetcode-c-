
using namespace std;


class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left=1,right=maxSum+1;
        while(left+1<right){
            int mid=(long)(left+right)>>1;
            long sum=mid;
            if(index>=mid-1){
                sum+=(long)mid*(mid-1)/2+(index-mid+1);
            }else{
                sum+=(long)(2*mid-1-index)*index/2;
            }
            if(n-index>=mid){
                sum+=(long)mid*(mid-1)/2+(n-index-mid);
            }else{
                sum+=(long)(2*mid-n+index)*(n-index-1)/2;
            }
            if(sum<=maxSum)left=mid;
            else right=mid;
        }
        return left;
    }
};


class Solution {
public:
    int countEven(int num) {
        auto isEven=[&](int n){
            int sum=0;
            while(n>0){
                sum+=n%10;
                n/=10;
            }
            return sum%2==0;
        };
        int res=0;
        for(int i=1;i<=num;++i){
            if(isEven(i)){
                res++;
            }
        }
        return res;
    }
};
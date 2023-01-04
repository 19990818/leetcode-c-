#include<math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int maxNum=max(max(a,b),c);
        int sum=a+b+c;
        return min(sum/2,sum-maxNum);
    }
};


class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res=0;
        for(string op:operations){
            if(op=="X++"||op=="++X"){
                res++;
            }else{
                res--;
            }
        }
        return res;
    }
};


class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res="";
        while(word1!=""&&word2!=""){
            if(word1<word2){
                res+=word2[0];
                word2=word2.substr(1);
            }else{
                res+=word1[0];
                word1=word1.substr(1);
            }
        }
        return res+word1+word2;
    }
};


class Solution {
public:
    int minimumBoxes(int n) {
        int i=1,j=1,cur=1;
        while(n>cur){
            n-=cur;
            i+=1;
            cur+=i;
        }
        cur=1;
        while(n>cur){
            n-=cur;
            ++j,++cur;
        }
        return i*(i-1)/2+j;
    }
};

class Solution {
public:
    int countHomogenous(string s) {
        int res=0,mod=1e9+7;
        s+='A';
        char temp=s[0];
        int cnt=0;
        for(char c:s){
            if(c==temp){
                ++cnt;
            }else{
               res=(long long)(res+(long long)cnt*(cnt+1)/2)%mod;
               temp=c,cnt=1; 
            }
        }
        return res;
    }
};

class Solution {
public:
    int minimumMoves(string s) {
        int res=0;
        for(int i=0;i<s.size();++i){
            if(s[i]=='X'){
                res++;
                i+=2;
            }
        }
        return res;
    }
};


class Solution {
public:
    int captureForts(vector<int>& forts) {
        return max(cntNum(0,1,forts),cntNum(forts.size()-1,-1,forts));
    }
    int cntNum(int start,int step,vector<int>& forts){
        int res=0,cnt=0;
        bool flag=false;
        while(start>=0&&start<forts.size()){
            if(forts[start]==1){
                flag=true;
                cnt=0;
            }else if(forts[start]==0&&flag){
                ++cnt;
            }else if(forts[start]==-1){
                flag=false;
                res=max(res,cnt);
                cnt=0;
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string,int> m;
        const int add=-3,sub=1;
        for(string v:positive_feedback)m[v]=add;
        for(string v:negative_feedback)m[v]=sub;
        vector<vector<int>> grades(student_id.size());
        int i=0;
        for(string rep:report){
            auto words=split(rep);
            int grade=0;
            for(auto word:words) grade+=m[word];
            grades[i]={grade,student_id[i]};
            ++i;
        }
        sort(grades.begin(),grades.end());
        vector<int> res(k,0);
        for(int i=0;i<k;++i) res[i]=grades[i][1];
        return res;
    }
    vector<string> split(string s){
        vector<string> ans;
        s+=" ";
        string temp="";
        for(char c:s){
            if(c==' '){
                if(temp!="") ans.push_back(temp);
                temp="";
            }else{
                temp+=c;
            }
        }
        return ans;
    }
};



class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long left=2,right=2e9;
        auto lcm=[&](int a,int b){
            long sum=(long)a*b;
            while(b>0){
                int t=b;
            b=a%b;
            a=t;
            }
            return sum/a;
        };
        auto check=[&](long k){
            long cnt1=k/divisor1,cnt2=k/divisor2,cnt3=k/lcm(divisor1,divisor2);
            long both=k-cnt1-cnt2+cnt3;
            long forArr1=cnt2-cnt3;
            long forArr2=cnt1-cnt3;
            return max(uniqueCnt1-forArr1,0l)+max(uniqueCnt2-forArr2,0l)<=both;
        };
        while(left<right){
            long mid=(right+left)>>1;
            if(check(mid))right=mid;
            else left=mid+1;
        }
        return left;
    }
};


class Solution {
public:
    int minimumLength(string s) {
        int start=0,end=s.size()-1;
        while(start<end&&s[start]==s[end]){
            int i=start,j=end;
            while(i<s.size()&&s[i]==s[start]){
                ++i;
            }
            while(j>=0&&s[j]==s[end]){
                --j;
            }
            start=i,end=j;
        }
        return max(end-start+1,0);
    }
};


class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int res=-1;
        for(int i=0;i<n;++i){
            if(words[(i+startIndex)%n]==target){
                if(res==-1){
                    res=min(i,n-i);
                }else{
                    res=min(i,min(res,n-i));
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k==0) return 0;
        int n=s.size();
        s+=s;
        unordered_map<char,int> full;
        vector<int> cnt={0,0,0};
        int i=0,j=0;
        int res=-1;
        while(i<n&&j<s.size()){
            while((full.size()<3&&j<s.size()) or (i!=0&&j<n)){
                cnt[int(s[j]-'a')]++;
                if(cnt[int(s[j]-'a')]>=k){
                    full[s[j]]=1;
                }
                ++j;
            }
            if(full.size()==3&&(i==0||j>=n)&&j-i<=n){
                if(res==-1)res=j-i;
                else res=min(res,j-i);
            }
            cnt[int(s[i]-'a')]--;
            if(cnt[int(s[i]-'a')]<k){
                full.erase(s[i]);
            }
            i++;
        }
        return res;
    }
};
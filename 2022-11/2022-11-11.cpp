#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool halvesAreAlike(string s) {
        string temp="aeiouAEIOU";
        int part=0,sum=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(temp.find(s[i])!=string::npos){
                sum++;
                if(i<n/2) part++;
            }
        }
        return sum==2*part;
    }
};

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        unordered_map<int,int> m;
        priority_queue<int,vector<int>,greater<int>> q;
        int n=apples.size();
        int res=0;
        for(int i=0;i<n;i++){
            if(m[i+days[i]]==0)
                q.push(i+days[i]);
            m[i+days[i]]+=apples[i];
            res=eat(q,m,i,res);
        }
        for(int i=n;!q.empty();i++){
            res=eat(q,m,i,res);
        }
        return res;
    }
    int eat(priority_queue<int,vector<int>,greater<int>> &q,
    unordered_map<int,int>&m,int d,int res){
        int temp=q.top();
        q.pop();
        for(;!q.empty()&&temp<=d;){
            temp=q.top();
            q.pop();
        }
        m[temp]--;
        if(temp>d&&m[temp]>=0){
            res++;
            if (m[temp]>0){
                q.push(temp);
            }
        }
        return res;
    }
};
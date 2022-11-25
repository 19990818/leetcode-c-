#include <vector>
#include <string>
#include <functional>
using namespace std;

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        function<vector<vector<int>>(string)> trans=[&](string s){
            vector<vector<int>> a;
            s=s+"1";
            int temp=int(s[0]-'a');
            int cnt=1;
            for(int i=1;i<s.size();i++){
                if(int(s[i]-'a')!=temp){
                    a.push_back({temp,cnt});
                    temp=int(s[i]-'a'),cnt=1;
                }else{
                    cnt+=1;
                }
            }
            return a;
        };
        vector<vector<int>> des=trans(s);
        int res=0;
        for(auto word:words){
            vector<vector<int>> src=trans(word);
            if(src.size()!=des.size()) continue;
            bool flag=true;
            for(int i=0;i<src.size();i++){
                if(!(src[i][0]==des[i][0]&&(src[i][1]==des[i][1]||des[i][1]>2)&&(des[i][1]>=src[i][1]))){
                    flag=false;
                    break;
                }
            }
            if(flag) res++;
        }
        return res;
    }
};


class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=edges.size()+1;
        vector<vector<int>> g(n,vector<int>(0));
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        vector<int> bobTime(n,n);
        function<bool(int,int,int)> dfsBob=[&](int c,int p,int t){
            if(c==0){
                bobTime[c]=t;
                return true;
            }
            for(auto y:g[c]){
                if(y!=p &&dfsBob(y,c,t+1)){
                    bobTime[c]=t;
                    return true;
                }
            }
            return false;
        };
        dfsBob(bob,-1,0);
        int res=INT32_MIN;
        g[0].push_back(-1);
        function<void(int,int,int,int)> dfsAlice=[&](int c,int p,int t,int total){
            if(t<bobTime[c]) total+=amount[c];
            else if(t==bobTime[c]) total+=amount[c]/2;
            if(g[c].size()==1){
                res=max(res,total); 
                return;
            }
            for(auto y:g[c]){
                if(y!=p){
                    dfsAlice(y,c,t+1,total);
                }
            }  
        };
        dfsAlice(0,-1,0,0);
        return res;
    }
};
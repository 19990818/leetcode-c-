#include <string>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool isCircularSentence(string sentence) {
      for(int i=0;i<sentence.size();i++){
        if(sentence[i]==' '){
            if(sentence[i-1]!=sentence[i+1]){
                return false;
            }
        }
      } 
      return sentence[0]==sentence[sentence.size()-1];
    }   
};


class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long ans=0;
        int temp=skill[0]+skill[skill.size()-1];
        for(int i=0,j=skill.size()-1;i<j;i++,j--){
            if(temp!=skill[i]+skill[j])return -1;
            ans+=(long long)(skill[i]*skill[j]);
        }
        return ans;
    }
};


class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int res=INT_MAX;
        vector<vector<vector<int>>> g(n+1);
        for(vector<int> road:roads){
            g[road[0]].push_back({road[1],road[2]});
            g[road[1]].push_back({road[0],road[2]});
        }
        vector<int> q={1};
        vector<int> t(n+1,0);
        t[1]=1;
        while(q.size()>0){
            vector<int> temp=q;
            q={};
            while(temp.size()>0){
                int cur=temp[temp.size()-1];
                temp.pop_back();
                for(auto v:g[cur]){
                    if(t[v[0]]==0){
                        t[v[0]]=1;
                        q.push_back(v[0]);
                    }
                    res=min(res,v[1]);
                }
            }
        }
        return res;
    }
};
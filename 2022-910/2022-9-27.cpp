#include <iostream>
#include <map>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size()!=s2.size()){
            return false;
        }
        map<char,int> m1,m2;
        for (int i=0;i<s1.length();i++){
            m1[s1[i]]++;
            m2[s2[i]]++;
        }
        map<char,int>::iterator iter;
        for(iter=m1.begin();iter!=m1.end();iter++){
            char k=iter->first;
            int v=iter->second;
            if(m2[k]!=v){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> nodeArr(n+1);
        for(vector<int> dislike:dislikes){
            nodeArr[dislike[0]].push_back(dislike[1]);
            nodeArr[dislike[1]].push_back(dislike[0]);
        }
        vector<int> travel(n+1);
        function<bool(int,int)> bfs=[&](int start,int color){
            travel[start]=color;
            vector<int> queue={start};
            while(true){
                vector<int> temp;
                color^=3;
                while (queue.size()>0){
                    int cur=queue[queue.size()-1];
                    queue.pop_back();
                    for(int child:nodeArr[cur]){
                        if (travel[child]!=0&&travel[child]!=color){
                            return false;
                        }
                        if (travel[child]==0){
                            travel[child]=color;
                            temp.push_back(child);
                        }
                    }
                }
                if (temp.size()==0){
                    break;
                }
                queue=temp;
            }
            return true;
        };
        for(int i=1;i<=n;i++){
            if (travel[i]==0&&!bfs(i,1)){
                return false;
            }
        }
        return true;
    }
};
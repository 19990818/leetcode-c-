#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <set>
using namespace std;
// #788 旋转数字 与翻转前相比的数字 应该是至少需要包含2,5,6,9个数>=1
// 然后0,1,8可以包含>=0个
class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=2;i<=n;++i){
            if(isRotateDigits(i)){
                ans++;
            }
        }
        return ans;
    }
    bool isRotateDigits(int n){
        string s=to_string(n);
        map<int,int> m={{1,1},{2,1},{0,1},{5,1},{6,1},{8,1},{9,1}};
        map<int,int> m2={{2,1},{5,1},{6,1},{9,1}};
        bool flag=false;
        for(int i=0;i<s.length();i++){
            if(m[int(s[i]-'0')]==0){
                return false;
            }
            if(m2[int(s[i]-'0')]==1){
                flag=true;
            }
        }
        return flag;
    }
};



class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<pair<int,int>,int> m;
        for (vector<int> obstacle:obstacles){
            m[pair(obstacle[0],obstacle[1])]=1;
        }
        int status=0;
        int ans=0;
        vector<int> dx={0,1,0,-1},dy={1,0,-1,0};
        int curx=0,cury=0;
        for(int command:commands){
            if(command==-1)
                status=(status+1)%4;
            else if(command==-2)
                status=(status+3)%4;
            else{
                for (int i=0;i<command&&m[pair(curx+dx[status],cury+dy[status])]==0;i++){
                    curx=curx+dx[status];
                    cury=cury+dy[status];
                }
                //cout<<curx<<cury<<endl;
                ans=max(ans,curx*curx+cury*cury);
            }
        }
        return ans;
    }
};
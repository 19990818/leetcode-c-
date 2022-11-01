#include <vector>
#include <functional>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        unordered_map<int,int> travel;
        vector<vector<int>> tos={{-1,0},{1,0},{0,-1},{0,1}};
        int cnt=1;
        vector<int> part1;
        function<void(int)> bfs=[&](int cur){
            if(cnt==1) part1.push_back(cur);
            vector<int> queue={cur};
            while(true){
                vector<int> temp;
                while(queue.size()>0){
                    int now=queue[queue.size()-1];
                    queue.pop_back();
                    int x=now/n,y=now%n;
                    for(vector<int> to:tos){
                        if(x+to[0]<m&&x+to[0]>=0&&y+to[1]>=0&&y+to[1]<n&&grid[x+to[0]][y+to[1]]==1
                        &&travel[(x+to[0])*n+y+to[1]]==0){
                            travel[(x+to[0])*n+y+to[1]]=cnt;
                            temp.push_back((x+to[0])*n+y+to[1]);
                            if(cnt==1)part1.push_back((x+to[0])*n+y+to[1]);
                        }
                    }
                }
                if(temp.size()==0)break;
                queue=temp;
            }
        };
         
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&travel[i*n+j]==0){
                    travel[i*n+j]=cnt;
                    bfs(i*n+j);
                    cnt++;
                }
            }
        }
        // for(auto it:travel){
        //     cout<<"why"<<endl;
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        int res=0;
        while(true){
            vector<int> temp;
            while(part1.size()>0){
                int now=part1[part1.size()-1];
                part1.pop_back();
                int x=now/n,y=now%n;
                for(vector<int> to:tos){
                    if(x+to[0]<m&&x+to[0]>=0&&y+to[1]>=0&&y+to[1]<n){
                        if(grid[x+to[0]][y+to[1]]==0){
                            grid[x+to[0]][y+to[1]]=1;
                            temp.push_back((x+to[0])*n+y+to[1]);
                        }else if(travel[(x+to[0])*n+y+to[1]]==2){
                            return res;
                        }
                    }
                }
            }
            res++;
            if(temp.size()==0)break;
            part1=temp;
        }
        return -1;
    }
};



class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res=1;
        for(int num:nums){
            if(num<0){
                num*=-1;
            }else if(num==0){
                return 0;
            }
        }
        return res;
    }
};
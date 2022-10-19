#include<vector>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;


class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cnt1=0,cnt0=0;
        for(int stu:students){
            if(stu==1)cnt1++;
            else cnt0++;
        }
        for(int saw:sandwiches){
            if(saw==1)cnt1--;
            else cnt0--;
            if (cnt0<0||cnt1<0) break;
        }
        return max(cnt1,cnt0);
    }
};


class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        vector<pair<int,int>> ps(values.size());
        for(int i=0;i<values.size();i++)ps[i]=make_pair(values[i],labels[i]);
        int ans=0;
        unordered_map<int,int> m;
        sort(ps.begin(),ps.end());
        for(int i=ps.size()-1;i>=0&&numWanted>0;i--){
            if(m[ps[i].second]<useLimit){
               //cout<<ps[i].first<<" "<<ps[i].second<<endl;
                m[ps[i].second]++;
                ans+=ps[i].first;
                numWanted--;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(grid[0][0]==1||grid[m-1][n-1]==1)return -1;
        int cnt=1;
        unordered_map<int,int> travel;
        vector<int> queue={0};
        vector<vector<int>> tos={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
        while(true){
            vector<int> temp;
            while(queue.size()>0){
                int cur=queue[queue.size()-1];
                if(cur==m*n-1){
                    return cnt;
                }
                queue.pop_back();
                int x=cur/n,y=cur%n;
                for(vector<int> to:tos){
                    if(x+to[0]<m&&x+to[0]>=0&&y+to[1]<n&&y+to[1]>=0&&
                    grid[x+to[0]][y+to[1]]==0&&travel[(x+to[0])*n+y+to[1]]==0){
                        travel[(x+to[0])*n+y+to[1]]=1;
                        temp.push_back((x+to[0])*n+y+to[1]);
                    }
                }
            }
            if(temp.size()==0)break;
            queue=temp;
            cnt++;
        }
        return -1;
    }
};

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        ans.push_back(label);
        function<int(int a)> sum=[&](int a){
            for(int i=30;i>=0;i--){
                if(a>=1<<i){
                    return 3*(1<<i)-1;
                }
            }
            return 0;
        };
        while(label>1){
            label/=2;
            ans.push_back(sum(label)-label);
            label=ans[ans.size()-1];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

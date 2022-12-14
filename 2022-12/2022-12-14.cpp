#include <vector>
#include <algorithm>
#include <functional>
using namespace std;




class Solution {
public:
    int findParent(int a,vector<int>& parent){
        if(a==parent[a])return a;
        parent[a]=findParent(parent[a],parent);
        return parent[a];
    }
    void merge(int a,int b,vector<int>& parent){
        int pa=findParent(a,parent),pb=findParent(b,parent);
        parent[pa]=pb;
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        sort(edgeList.begin(), edgeList.end(), [&](vector<int> &e1, vector<int> &e2) {
            return e1[2] < e2[2];
        });

        vector<int> index(queries.size());
        for(int i=0;i<queries.size();++i) index[i]=i;
        sort(index.begin(), index.end(), [&](int i1, int i2) {
            return queries[i1][2] < queries[i2][2];
        });
        vector<int> parent(n);
        for(int i=0;i<n;++i) parent[i]=i;
    
        int j=0;
        vector<bool> res(queries.size());
        for(int i:index){
            while(j<edgeList.size()&&edgeList[j][2]<queries[i][2]){
                merge(edgeList[j][0],edgeList[j][1],parent);
                ++j;
            }
            res[i]=findParent(queries[i][0],parent)==findParent(queries[i][1],parent);
        }
        return res;
    }
};
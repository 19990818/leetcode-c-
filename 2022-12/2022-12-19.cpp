#include <vector>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> parent(n,0);
        for(int i=0;i<n;i++)parent[i]=i;
        for(auto edge:edges){
            merge(edge[0],edge[1],parent);
        }
        return findParent(source,parent)==findParent(destination,parent);
    }
    int findParent(int a,vector<int>& parent){
        if(a==parent[a]) return a;
        parent[a]=findParent(parent[a],parent);
        return parent[a];
    }
    void merge(int a,int b,vector<int>& parent){
        int pa=findParent(a,parent),pb=findParent(b,parent);
        parent[pa]=pb;
    }
};
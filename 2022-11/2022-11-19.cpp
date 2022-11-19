#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res=0,temp=0;
        for(int v:gain){
            temp+=v;
            res=max(res,temp);
        }
        return res;
    }
};


class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        int n=nums.size();
        int mod=1e9+7;
        sort(nums.begin(),nums.end());
        vector<int> p(n,0);
        p[0]=1;
        for(int i=1;i<n;i++)
            p[i]=(p[i-1]*2)%mod;
        int res=0;
        for(int i=0;i<n;i++){
             int temp=(p[i]-p[n-i-1])*1ll*(nums[i])%mod;
             res=(res+temp)%mod;
        }
        return res;
    }
};
struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        vector<TreeNode*> q;
        q.push_back(root);
        int ans=0;
        while(q.size()>0){
            vector<TreeNode*> temp=q;
            vector<int> a(temp.size(),0),id(temp.size(),0);
            q.clear();
            for(int i=0;i<temp.size();i++){
                id[i]=i;
                a[i]=temp[i]->val;
                if(temp[i]->left!=nullptr)
                    q.push_back(temp[i]->left);
                if(temp[i]->right!=nullptr)
                    q.push_back(temp[i]->right);
            }
            sort(id.begin(),id.end(),[&](int i,int j){
                return a[i]<a[j];
            });
            vector<bool> vis(temp.size(),false);
            ans+=temp.size();
            for(int i=0;i<temp.size();i++){
                if(!vis[i]){
                    for(int p=i;!vis[p];p=id[p]){
                        vis[p]=true;
                    }
                    ans--;
                }
            }
        }
        return ans;
    }
};
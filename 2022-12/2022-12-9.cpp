#include <vector>
#include <string>
#include <functional>
using namespace std;


class Solution {
public:
    bool checkPowersOfThree(int n) {
        const int a=16;
        vector<int> pow3(a,0);
        pow3[0]=1;
        for(int i=1;i<a;++i)pow3[i]=pow3[i-1]*3;
        for(int i=15;i>=0;--i){
            if(n>=pow3[i]){
                n-=pow3[i];
                if(n==0){
                    return true;
                }
            }
        }
        return false;
    }
};


class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> masks;
        for(string a:arr){
            int mask=0;
            for(char c:a){
                if((mask&(1<<int(c-'a')))==0){
                    mask|=(1<<int(c-'a'));
                }else{
                    mask=0;break;
                }
            }
            masks.push_back(mask);
        }
        int ans=0;
        function<void(int,int)> dfs=[&](int pos,int mask){
            if(pos==masks.size()){
                ans=max(ans,__builtin_popcount(mask));
                return;
            }
            if((masks[pos]&mask)==0){
                dfs(pos+1,mask|masks[pos]);
            }
            dfs(pos+1,mask);
        };
        dfs(0,0);
        return ans;
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
    int deepestLeavesSum(TreeNode* root) {
        vector<TreeNode*> q={root};
        int res=root->val;
        while(q.size()>0){
            auto temp=q;
            q={};
            int tempRes=0;
            while(temp.size()>0){
                auto cur=temp[temp.size()-1];
                temp.pop_back();
                tempRes+=cur->val;
                if(cur->left!=nullptr){
                    q.push_back(cur->left);
                }
                if(cur->right!=nullptr){
                    q.push_back(cur->right);
                }
            }
            res=tempRes;
        }
        return res;
    }   
};
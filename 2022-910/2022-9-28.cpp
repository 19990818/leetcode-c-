#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        vector<int> queue={1};
        int tp=0,fp=0,sp=0;
        for (int i=1;i<k;i++){
            int temp=min(queue[tp]*3,queue[fp]*5);
            temp=min(temp,7*queue[sp]);
            if(queue[tp]*3==temp){
                tp++;
            }
            if (queue[fp]*5==temp) fp++;
            if(queue[sp]*7==temp) sp++;
            queue.push_back(temp);
        }
        return queue[queue.size()-1];
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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.size()==0) return nullptr;
        int i=1;
        for(;i<preorder.size()&&preorder[i]!=postorder[postorder.size()-2];i++);
        TreeNode* root=new(TreeNode);
        root->val=preorder[0];
        vector<int> leftPre,leftPost,rightPre,rightPost;
        for(int j=1;j<i;j++){
            leftPre.push_back(preorder[j]);
            leftPost.push_back(postorder[j-1]);  
        }
        for(int j=i;j<preorder.size();j++){
            rightPost.push_back(postorder[j-1]);
            rightPre.push_back(preorder[j]);
        }
        root->left=constructFromPrePost(leftPre,leftPost);
        root->right=constructFromPrePost(rightPre,rightPost);
        return root;
    }
};


class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        map<int,int> m;
        m[arr[0]]=1;
        for(int i=1;i<arr.size();i++){
            m[arr[i]]=1;
            for(int j=i-1;j>=0&&(arr[j]|arr[i])!=arr[j];j--){
                arr[j]|=arr[i];
                m[arr[j]]=1;
            }
        }
        return m.size();
    }
};


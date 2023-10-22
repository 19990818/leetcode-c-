#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


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
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<TreeNode*> q={root},temp;
        vector<int> sumA={root->val};
        unordered_map<TreeNode*,int> brother;
        while(q.size()>0){
            temp=q;
            q.clear();
            int sum=0;
            for(int i=0;i<temp.size();++i){
                if(temp[i]->left!=nullptr&&temp[i]->right!=nullptr){
                    brother[temp[i]->left]=temp[i]->right->val;
                    brother[temp[i]->right]=temp[i]->left->val;
                    sum+=(temp[i]->right->val+temp[i]->left->val);
                    q.push_back(temp[i]->left);
                    q.push_back(temp[i]->right);
                }else if (temp[i]->left!=nullptr){
                    sum+=temp[i]->left->val;
                    q.push_back(temp[i]->left);
                }else if (temp[i]->right!=nullptr){
                    sum+=temp[i]->right->val;
                    q.push_back(temp[i]->right);
                }
                temp[i]->val=sumA[sumA.size()-1]-temp[i]->val-brother[temp[i]];
            }
            sumA.push_back(sum);
        }
        return root;
    }
};



class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> res={0,0};
        for(int i=0;i<mat.size();i++){
            int cnt=0;
            for(auto v:mat[i]){
                if(v==1){
                    cnt++;
                }
            }
            if(cnt>res[1]){
                res={i,cnt};
            }
        }
        return res;
    }
};

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        sort(divisors.begin(),divisors.end());
        int res=divisors[0];
        int mcnt=0;
        for(int d:divisors){
            int cnt=0;
            for(int num:nums){
                if(num%d==0){
                    cnt++;
                }
            }
            if(cnt>mcnt){
                mcnt=cnt;
                res=d;
            }
        }
        return res;
    }
};


class Solution {
public:
    int addMinimum(string word) {
        int cnt=1;
        for(int i=1;i<word.size();i++){
            if(word[i]<=word[i-1]){
                cnt++;
            }
        }
        return 3*cnt-word.size();
    }
};
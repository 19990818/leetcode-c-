#include <vector>
#include <algorithm>
#include <functional>
using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int sum1=sum(nums1),sum2=sum(nums2);
        int diff=abs(sum1-sum2);
        if(diff==0)return 0;
        int res=0;
        if(sum1>sum2)swap(nums1,nums2);
        for(int left=0,right=nums2.size()-1;left<nums1.size()||right>=0;){
            if(right==-1||(left<nums1.size()&&nums1[left]+nums2[right]<7)){
                diff-=(6-nums1[left]);
                ++left;
            }else{
                diff-=(nums2[right]-1);
                --right;
            }
            ++res;
            if(diff<=0) return res;
        }
        return -1;
    }
    int sum(vector<int> a){
        int res=0;
        for(int v:a){
            res+=v;
        }
        return res;
    }
};


class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left=findKthOdd(nums,1),right=findKthOdd(nums,k);
        if(right==-1) return 0;
        int res=0;
        int lc=left+1,rc=1;
        while(right<nums.size()){
            ++right;
            while(right<nums.size()&&nums[right]%2==0){
                ++right;
                ++rc;
            }
            res+=lc*rc;
            lc=1,rc=1;
            ++left;
            while(left<nums.size()&&nums[left]%2==0){
                ++left;
                ++lc;
            }
        }
        return res;
    }
    int findKthOdd(vector<int> &nums,int k){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
                cnt++;
            }
            if(cnt==k) return i;
        }
        return -1;
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res1=inorder(root1),res2=inorder(root2);
        return merge(res1,res2);
    }
    vector<int> inorder(TreeNode *root){
        vector<int> res;
        function<void(TreeNode *)> dfs=[&](TreeNode * r){
            if(r==nullptr)return;
            dfs(r->left);
            res.push_back(r->val);
            dfs(r->right);
        };
        dfs(root);
        return res;
    }
    vector<int> merge(vector<int> &a,vector<int> &b){
        int i=0,j=0;
        vector<int> res;
        while(i<a.size()&&j<b.size()){
            if(a[i]<=b[j]){
                res.push_back(a[i]);
                i++;
            }else{
                res.push_back(b[j]);j++;
            } 
        }
        while(i<a.size()){
            res.push_back(a[i]);i++;
        }
        while(j<b.size()){
            res.push_back(b[j]);j++;
        }
        return res;
    }
};
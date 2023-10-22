#include <vector>
#include <algorithm>
#include <string>
using namespace std;



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());
    }
};


class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n=nums.size();
        int res=-1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSameMax(nums[i],nums[j])){
                    res=max(res,nums[i]+nums[j]);
                }
            }
        }
        return res;
    }
    bool isSameMax(int a,int b) {
        vector<int> as=splitNum(a);
        sort(as.begin(),as.end());
        vector<int> bs=splitNum(b);
        sort(bs.begin(),bs.end());
        return as[as.size()-1]==bs[bs.size()-1];
    }
    vector<int> splitNum(int a) {
        vector<int> res=vector<int>();
        while(a>0){
            res.push_back(a%10);
            a/=10;
        }
        return res;
    }
};

 struct ListNode {
     int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        vector<int> nums= vector<int>();
        while(head!=nullptr){
            nums.push_back(head->val);
            head=head->next;
        }
        int c=0;
        ListNode *res=nullptr;
        for(int i=nums.size()-1;i>=0||c>0;i--){
            int t=c;
            if(i>=0){
                t+=2*nums[i];
            }
            ListNode* tl=new ListNode(t%10);
            tl->next=res;
            res=tl;
            c=t/10;
        }
        return res;
    }
};
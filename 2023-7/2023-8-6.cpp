#include <unordered_map>
#include <vector>
using namespace std;





struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* res=new ListNode(0);
        res->next=head;
        ListNode* cur=res;
        while(head!=nullptr&&head->next!=nullptr){
            ListNode* temp=head->next;
            ListNode* next=head->next->next;
            temp->next=head;
            cur->next=temp;
            head->next=next;
            head=next;
        }
        return res->next;
    }
};


class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        return 100-int(purchaseAmount/10)*10;
    }
};


class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* res=head;
        while(head->next!=nullptr){
            ListNode* temp=head->next;
            ListNode* insertNode=new ListNode(gcd(head->val,head->next->val));
            head->next=insertNode;
            insertNode->next=temp;
            head=temp;
        }
        return res;
    }
    int gcd(int a,int b){
        while(b!=0){
            int t=b;
            b=a%b;
            a=t;
        }
        return a;
    }
};


class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]].push_back(i);
        }
        int n=nums.size();
        int res=n;
        for(auto k:m){
            int temp=0;
            for(int i=0;i<k.second.size();i++){
                if(i<k.second.size()-1){
                    temp=max(temp,(k.second[i+1]-k.second[i])/2);
                }else{
                    temp=max(temp,(n-k.second[i]+k.second[0])/2);
                }
            }
            res=min(res,temp);
        }
        return res;
    }
};


class Solution {
public:
    string finalString(string s) {
        string res="";
        for(char c:s){
            if(c=='i'){
                res=reverseStr(res);
            }else{
                res+=c;
            }
        }
        return res;
    }
    string reverseStr(string s){
        string ans="";
        for(char c:s){
            ans=c+ans;
        }
        return ans;
    }
};
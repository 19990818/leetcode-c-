#include <unordered_map>
#include <vector>
#include <stdio>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr||head->next==nullptr){
            return nullptr;
        }
        ListNode *slow=head->next,*fast=head->next->next;
        while(slow!=nullptr&&fast!=nullptr&&fast->next!=nullptr&&slow!=fast){
            slow=slow->next; 
            fast=fast->next->next;
        }
        if(slow==fast){
            slow=head;
            while(slow!=fast){
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
        return nullptr;
    }
};

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int res=0;
        for(int hour:hours){
            if(hour>=target){
                res++;
            }
        }      
        return res;
    }
};


class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int res=0;
        int left=0,right=0;
        unordered_map<int,int> m,temp;
        for(int num:nums){
            m[num]=1;
        }
        while(left<=right){
            while(right<nums.size()&&temp.size()<m.size()){
                temp[nums[right]]++;
                right++;
            }
            if(temp.size()==m.size()){
                res+=nums.size()-right+1;
            }
            if(left<nums.size()){
                temp[nums[left]]--;
                if(temp[nums[left]]==0){
                    temp.erase(nums[left]);
                }
            }
            left++;
        }
        return res;
    }
};


class Solution {
public:
    string res;
    string minimumString(string a, string b, string c) {
        vector<string> ss = {a,b,c};
        res=a+b+c;
        unordered_map<int,int> m;
        dfs("",ss,m);
        return res;
    }
    void dfs(string cur,vector<string> &ss,unordered_map<int,int> m){
        if(m.size()==ss.size()){
            if(cur.size()<res.size()||(cur.size()==res.size()&&cur<res)){
                res=cur;
            }
            return;
        }
        for(int i=0;i<ss.size();i++){
            if(m[i]==0){
                if(cur.find(ss[i])!=-1){
                    m[i]=1;
                    dfs(cur,ss,m);
                    m.erase(i);
                    continue;
                }
                for(int j=0;j<=cur.size();j++){
                    if(cur.size()-j<=ss[i].size()&&cur.substr(j)==ss[i].substr(0,cur.size()-j)){
                        m[i]=1;
                        dfs(cur+ss[i].substr(cur.size()-j),ss,m);
                        m.erase(i);
                        break;
                    }
                }
            }
        }
    }
};   
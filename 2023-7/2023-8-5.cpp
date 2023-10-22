#include<vector>
#include<math.h>
#include<algorithm>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* res=new ListNode(0);
        ListNode* temp=res;
        while(list1!=nullptr||list2!=nullptr){
            if(list2==nullptr||(list1!=nullptr&&list1->val<=list2->val)){
                temp->next=list1;
                list1=list1->next;
            }else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }        
        return res->next;
    }
};



class Solution {
public:
    struct edge
    {
        /* data */
        int x;
        int y;
        int dis;
    };
    int find(vector<int>& parent,int a){
        while(a!=parent[a]){
            a=parent[a];
        }
        return parent[a];
    }
    int merge(vector<int>& parent,vector<int>& dis, edge e){
        int rootx=find(parent,e.x);
        int rooty=find(parent,e.y);
        if(rootx==rooty){
            return 0;
        }
        parent[rooty]=rootx;
        dis[rootx]+=dis[rooty]+e.dis;
        return dis[rootx];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> parent=vector<int>(n,0);
        vector<int> dis=vector<int>(n,0);
        vector<edge> edges;
        for(int i=0;i<n;i++){
            parent[i]=i;
            for(int j=i+1;j<n;j++){
                edges.push_back(edge{i,j,abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])});
            }
        }
        sort(edges.begin(),edges.end(),[&](edge x,edge y){
            return x.dis<y.dis;
        });
        int cnt=0;
        for(edge e:edges){
            int temp=merge(parent,dis,e);
            if(temp!=0){
                cnt++;
            }
            if(cnt==n-1){
                return temp;
            }
        }
        return 0;
    }
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
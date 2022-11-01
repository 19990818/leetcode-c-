#include <vector>
using namespace std;

class MyLinkedList {
public:
    struct ListNode
    {
        int val;
        ListNode *next; 
    };
    ListNode *l;
    int size;
    MyLinkedList() {
        l=nullptr;
        size=0;
    }
    
    int get(int index) {
        //cout<<l<<" "<<l->val<<endl;
        if (index<0||index>=size){
            return -1;
        }
        ListNode *cur=l;
        for(;index>0;index--){
            cur=cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode *newL=new(ListNode);
        newL->val=val;
        newL->next=l;
        l=newL;
        size++;
    }
    
    void addAtTail(int val) {
        ListNode *cur=l;
        if(cur==nullptr){
            ListNode *newL=new(ListNode);
            newL->val=val;
            newL->next=nullptr;
            l=newL;
            size++;
            return;
        }
        for(;cur->next!=nullptr;cur=cur->next);
        ListNode *node=new(ListNode);
        node->val=val;
        node->next=nullptr;
        cur->next=node;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index>size){
            return;
        }
        if (index==size){
            addAtTail(val);
            return;
        }
        if (index<=0){
            addAtHead(val);
            return;
        }
        ListNode *cur=l;
        for(;index>1;cur=cur->next,index--);
        ListNode *tempPost=cur->next;
        ListNode *newNode=new(ListNode);
        newNode->val=val;
        newNode->next=tempPost;
        cur->next=newNode;
        size++;
    }
    /*  */
    void deleteAtIndex(int index) {
        if(index>=size||index<0){
            return;
        }
        if (index==0){
            l=l->next;
            size--;
            return;
        }
        ListNode *cur=l;
        for (;index>1;cur=cur->next,index--);
        cur->next=cur->next->next;
        size--;
    }
};
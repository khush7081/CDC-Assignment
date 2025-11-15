#include<iostream>
using namespace std;
class ListNode{
public:
    int val;
    ListNode* next;
    ListNode( int v){
        val = v;
        next = NULL;
    }
};
    ListNode* rotateRight(ListNode* head, int k) {


        if(head==NULL) return head;
        ListNode* ptr=head;
        ListNode* tail;
        int len=0;
       
        
        while(ptr!=NULL){
            len++;
            tail=ptr;
            ptr=ptr->next;
        }
        ListNode *temp;
        if(k>=len) k=k%len;
        int idx=len-k-1;
        ptr=head;
        for(int i=1;i<=idx;i++) ptr=ptr->next;
        temp=ptr;
        tail->next=head;
        head=temp->next;
        temp->next=NULL;

        return head;
        

    }
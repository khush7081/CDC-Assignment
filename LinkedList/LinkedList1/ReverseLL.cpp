 
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
ListNode* reverseList(ListNode* head) {
        
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* Next=curr->next;
        while(Next!=NULL){
            Next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=Next;        
        }
        return prev;
}
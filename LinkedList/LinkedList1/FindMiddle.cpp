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
ListNode* middleNode(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        while(slow!=NULL){
            if(fast->next==NULL) return slow;
            if(fast->next->next==NULL) return slow->next;
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;

        
    }
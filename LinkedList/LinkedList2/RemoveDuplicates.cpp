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
  ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* ptr=head;
        ListNode* cpt=head->next;
        while(cpt!=NULL){
                if(ptr->val==cpt->val){
                    ptr->next=cpt->next;
                    cpt=cpt->next;
                }
                else{
                    ptr=cpt;
                    cpt=cpt->next;
                }                 
        } 
        return head;
        
    }
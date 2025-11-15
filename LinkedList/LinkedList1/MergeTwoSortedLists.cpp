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
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       

        if(list1==NULL && list2==NULL) return NULL;
        ListNode* a=list1;
        ListNode* b=list2;
        ListNode* res=new ListNode(100);
        ListNode* ptr=res;
        while(list1!=NULL && list2!=NULL){
            if(list1->val <= list2->val){
                ptr->next=list1;
                list1=list1->next;
            }
            else {
                ptr->next=list2;
                list2=list2->next;
            }
            ptr=ptr->next;
        }
        if(list1==NULL) ptr->next=list2;
        if(list2==NULL) ptr->next=list1;
        return res->next;
    }
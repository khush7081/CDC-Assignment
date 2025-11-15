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
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int sum=l1->val+l2->val;
            int carry=0;
            int n=sum;
            if(sum>=10){
                sum=sum%10;
                carry=n/10;
            }
            ListNode* l3=new ListNode(sum);
            ListNode* ptr=l3;
            l1=l1->next;
            l2=l2->next;

            while(l1!=NULL && l2!=NULL){
                sum=l1->val+l2->val;
                if(carry>0) sum+=carry;
                n=sum;
                if(sum>=10){
                    sum=sum%10;
                    carry=n/10;
                }
                else carry=0;
                ListNode* temp=new ListNode(sum);
                ptr->next=temp;
                ptr=temp;
                l1=l1->next;
                l2=l2->next;
            }
            while(l1!=NULL){
                int x=l1->val;
                if(carry>0) x+=carry;
                int m=x;
                if(x>=10){
                    x=x%10;
                    carry=m/10;
                }
                else carry=0;
                ListNode* temp=new ListNode(x);
                ptr->next=temp;
                ptr=temp;
                l1=l1->next;
                
            }
             while(l2!=NULL){
                int x=l2->val;
                if(carry>0) x+=carry;
                int m=x;
                if(x>=10){
                    x=x%10;
                    carry=m/10;
                }
                else carry=0;
                ListNode* temp=new ListNode(x);
                ptr->next=temp;
                ptr=temp;
                l2=l2->next;
            
            }
            if(carry>0){
                ListNode* temp=new ListNode(carry);
                ptr->next=temp;
                ptr=temp;
            }
            return l3;
        
    }
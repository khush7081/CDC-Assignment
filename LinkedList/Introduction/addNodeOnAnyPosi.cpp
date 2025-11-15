
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
class MyLinkedList {
public:
    ListNode* head;
    ListNode* tail;
    int size;
    MyLinkedList() {
        head = tail = NULL;
        size = 0;
    }
    
    int get(int index) {
        if( head ==  NULL) return -1;
        ListNode* ptr = head;
        int count = 0;
        while(ptr){
            if(count == index) return ptr->val;
            count++;
            ptr = ptr->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        if( head == NULL){
            ListNode* temp = new ListNode(val);
            head = tail = temp;
            size++;
            return;
        }
        ListNode* temp = new ListNode(val);
        temp->next= head;
        head = temp;
        size++;
    }
    
    void addAtTail(int val) {
        if( head == NULL){
            ListNode* temp = new ListNode(val);
            head = tail = temp;
            size++;
            return;
        }
        ListNode* temp = new ListNode(val);
        tail->next = temp;
        tail = temp; 
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if( index > size) return;
        if( index == 0){
            addAtHead(val);
            return;
        }
        if( index == size){
            addAtTail(val);
            return;
        }
        int count = 0;
        ListNode* ptr = head;
        while(ptr){
            if( count == index -1) break;
            count++;
            ptr = ptr->next;
        }
        ListNode* temp = new ListNode(val);
        temp->next = ptr->next;
        ptr->next = temp;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if( head == NULL) return;
        if( index >= size) return;
     
        if( index == 0){
            ListNode* ptr = head;
            head = head->next;
            delete(ptr);
            size--;
            return;
        }
        
        ListNode* ptr = head;
        ListNode* cpt = head;
        int count = 0;
        while(ptr){
            if(count == index) break;
            cpt = ptr;
            ptr=ptr->next;
            count++;
        }
        cpt->next = ptr->next;
        if( index == size-1) tail =cpt;
        ptr->next = NULL;
        delete(ptr);
        size--;
    }
};
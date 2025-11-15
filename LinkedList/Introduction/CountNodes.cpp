 #include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node( int v){
        val = v;
        next = NULL;
    }
};
 int getCount(Node* head) {
        if( head == NULL) return 0;
        // Code here
        Node* ptr= head;
        int count = 0;
        while(ptr){
            count++;
            ptr=ptr->next;
        }
        return count;
    }
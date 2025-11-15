#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class myQueue {
  vector<int>q;
  int front;
  int rear;
  public:
    myQueue(int n) {
        q.resize(n);
        front = rear = -1;
    }

    bool isEmpty() {
        if(front == -1) return true;
        return false;
    }

    bool isFull() {
        if( rear - front == q.size() - 1) return true;
        return false;
    }

    void enqueue(int x) {
        
        if( front == -1 ){
            front++;
        }
        if( rear == q.size() - 1) return;
        rear++;
        q[rear] = x;
    }

    void dequeue() {
        
        if( front == -1 ) return;
        if( front == rear){
            front = rear = -1;
            return;
        }
        front++;
        
    }

    int getFront() {
        if( front >= 0) return q[front];
        return -1;
        
    }

    int getRear() {
        
        if( front >= 0) return q[rear];
        return -1;
    }
};
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class MyCircularQueue {
public:
    int front;
    int back;
    int size;
    int capacity;
    vector<int>a;
    MyCircularQueue(int k) {
        front = 0;
        back = 0;
        size = 0;
        a.resize(k);
        capacity = k;
    }
    
    bool enQueue(int val) {
        if(back == capacity) back = 0;
        if(size < capacity){
            a[back] =  val;
            back++;
            size++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(size == 0) return false;
        front++;
        if(front == capacity) front = 0;
        size--;
        return true;
    }
    
    int Front() {
        if(size == 0) return -1;
        return a[front];
        
    }
    
    int Rear() {
        if(size == 0) return -1;
        if(back == 0) return a[capacity - 1];
        return a[back - 1];
        
    }
    
    bool isEmpty() {
        if(size == 0) return true;
        return false;
        
    }
    
    bool isFull() {
        if(size == capacity) return true;
        return false;
        
    }
};
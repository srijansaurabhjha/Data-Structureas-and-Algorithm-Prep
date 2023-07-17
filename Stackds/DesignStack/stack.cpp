#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int *arr;
    int cap;
    int nI; //nextIndex
public:
    
    Stack(int capacity) {
        // Write your code here.
        arr=new int[capacity];
        cap=capacity;
        nI=-1;
    }

    void push(int num) {
        // Write your code here.
        if(nI==cap){
            return ;
        }
        nI++;
        arr[nI]=num;
    }

    int pop() {
        // Write your code here.
        if(nI==-1)return -1;
        int value=arr[nI];
        nI--;
        return value;
    }
    
    int top() {
        // Write your code here.
        if(nI==-1)return -1;
        int value=arr[nI];
        return value;
    }
    
    int isEmpty() {
        // Write your code here.
        if(nI==-1)return 1;
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(nI==cap)return 1;
        return 0;
    }
    
};
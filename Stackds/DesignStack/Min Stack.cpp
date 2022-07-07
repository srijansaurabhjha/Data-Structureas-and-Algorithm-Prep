// https://www.interviewbit.com/problems/min-stack/

// 1st method

#include<bits/stdc++.h>
stack<pair<int,int>>s; //first->Value second->minathatlayer
MinStack::MinStack() {
    
    while(!s.empty()){
        s.pop();
    }
    
}

void MinStack::push(int x) {
    if(s.empty()){
        s.push({x,x});
        return;
    }
    
    auto Top=s.top();
    int curr_minVal=Top.second;
    
    if(curr_minVal>x)curr_minVal=x;
    
    s.push({x,curr_minVal});
}

void MinStack::pop() {
    if(s.empty())return;
    
    s.pop();
}

int MinStack::top() {
    if(s.empty())return -1;
    
    int Top=s.top().first;
    
    return Top;
}

int MinStack::getMin() {
    if(s.empty())return -1;
    
    int minElem=s.top().second;
    
    return minElem;
}


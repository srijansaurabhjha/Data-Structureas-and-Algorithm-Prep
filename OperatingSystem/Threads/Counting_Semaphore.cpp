#include<bits/stdc++.h>
using namespace std;

class Semaphore{
     private:
     int value;

     queue<Process>q;

     public:

     void wait(Semaphore s){
          s.value=s.value-1;
          while(s.value<0){
               q.push(q);
               block();
          }
     }

     void Signal(Semaphore s){
          s.value=s.value+1;
          if(s.value>=0){
               Process p=q.front();
               q.pop();
               wakeup(p);
          }
     }
};
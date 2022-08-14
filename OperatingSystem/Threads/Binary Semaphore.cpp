#include<bits/stdc++.h>
using namespace std;

class Semaphore{
    private:
    queue<Process>q;
    enum value{0,1};

    public:

    void wait(Semaphore s){
        if(s.value==1)s.value=0;
        else{
            q.push(P);
            sleep();
        }
    }

    void Signal(Semaphore s){
        if(s.q is empty)s.value=1;
        else{
            Process P=q.front();
            q.pop();
            wakeup(P);
        }
    }
};



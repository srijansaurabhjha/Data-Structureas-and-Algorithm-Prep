#include<iostream>
using namespace std;

do{
   
   wait(mutex);
    wait(fork[i]);
    wait(fork[(i+1)%k]);
   signal(mutex);
    //C.S

    signal(fork[i]);
    signal(fork[(i+1)%k]);

}while(1);
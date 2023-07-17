#include<iostream>
using namespace std;

do{
   
   wait(mutex); // Binary semaphore
    wait(fork[i]); // counting
    wait(fork[(i+1)%k]); //counting
   signal(mutex);//Binary semaphore
    //C.S

    signal(fork[i]);
    signal(fork[(i+1)%k]);

}while(1);

//odd even rule
//gs->dinning philosipher


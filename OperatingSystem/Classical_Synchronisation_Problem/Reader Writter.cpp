//Shared File

// If one person tries editing the file -> no other person should read it
// If some person is reading then others may read it at the same time.

// Solution
// 1. Mutex -> Binary Semaphore-> To ensure mutual exclusion for readcnt variable.
// 2.wrt
// 3.readcnt

//Writer Solution
do{

   wait(wrt);

   //C.s

   signal(wrt);

}while(1);


//Reader Solution
do{

    wait(mutex);

    readCnt++;

    if(readCnt==1)wait(wrt);

    signal(mutex);

    //C.S

    wait(mutex);
    readCnt--;

    if(readCnt==0)signal(wrt);

    signal(mutex);


}while(1);
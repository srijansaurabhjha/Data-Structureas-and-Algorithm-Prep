//Single Flag Solution -> Improvement -> Peterson's Solution

// 2 thread's Synchronization

// Flag[2] and turn-> 0/1

// T1
while (1)
{
    flag[0]=true;

    turn = 1;

    while(turn==1&&flag[1]==true);

    // C.S
    flag[0]=false;

}



//T2
while(1){

   flag[1]=true;

   turn=0;

   while(turn==0&&flag[0]==true);

//    C.S
   flag[1]=false;

}

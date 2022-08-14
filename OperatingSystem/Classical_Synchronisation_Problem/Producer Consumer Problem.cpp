// We have  a buffer of size n. A producer and a consumer . Producer can produce an item and can place it in the buffer. And consumer can consume it.
// We need to ensure that when a producer is placing an item in the buffer then at the same time consumer cannot consume any item.

// Therefore one can assume the following
// 1. Producer Thread
// 2. Consumer Thread
// 3. Buffer->Critical Section


// Solution
// Things Required:-
// 1. Binary Semaphore to acquire lock on buffer.
// 2. empty-> Counting Semaphore initial value is n
// 3. Full -> Counting semaphore initial value is 0

// Producer
do{

   wait(empty); -> //Have to wait until empty<0

   wait(mutex);

   //C.S

   signal(mutex);

   signal(full);

}while(1);


//Consumer
do{

     wait(full);

     wait(mutex);

     //C.S

     signal(mutex);

     signal(empty);

}while(1);
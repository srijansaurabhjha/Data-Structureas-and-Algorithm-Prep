#include<bits/stdc++.h>
#include<unistd.h>
#include<thread>
using namespace std;

void refresh1(map<string,int>weather1){
   
   int cnt1=5;

   while(cnt1--){
      for(auto& x:weather1){
         x.second++;
         cout<<x.first<<"->"<<x.second<<endl;
      }
     sleep(2);
   }

}

int main(){
     
    map<string,int>weather1={
        {"Delhi",28},
        {"Mumbai",20}
    };
    thread t1(refresh1,weather1);

    t1.join();


return 0;
}
//You are given N<=10^7 numbers,each between 0 to 10^9. How many different values appear in the sequence
#include<bits/stdc++.h>
using namespace std;

int main(){
   bitset<10000001>vis;
   int n;
   cout<<"Enter n: "; 
   cin>>n;
   for(int i=0;i<n;i++){
      int x;
      cin>>x;
      vis[x]=true;
   }
   cout<<vis.count();
return 0;
}
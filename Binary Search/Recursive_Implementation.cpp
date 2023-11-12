#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&arr,int target,int s,int e){
   int l=s;
   int h=e;
   while(l<=h){
      int mid=l+(h-l)/2;
      if(arr[mid]==target){
         return mid;
      }else if(arr[mid]>target){
         return f(arr,target,l,mid-1);
      }else return f(arr,target,mid+1,h);
   }
   return -1;
}

int main(){
   vector<int>arr={1,4,5,6,20,49,76,198,287,384};
   int target=49;

   cout<<f(arr,target,0,arr.size()-1)<<endl;
      
   return 0;
}
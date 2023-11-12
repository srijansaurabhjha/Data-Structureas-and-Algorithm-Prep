#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&arr,int target){
   int l=0;
   int h=arr.size()-1;
   while(l<=h){
      int mid=l+(h-l)/2;
      if(arr[mid]==target){
         return mid;
      }else if(arr[mid]>target){
         h=mid-1;
      }else l=mid+1;
   }
   return -1;
}

int main(){
   vector<int>arr={1,4,5,6,20,49,76,198,287,384};
   int target=49;

   cout<<f(arr,target)<<endl;
      
   return 0;
}
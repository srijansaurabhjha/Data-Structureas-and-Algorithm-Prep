// https://practice.geeksforgeeks.org/problems/longest-span-with-same-sum-in-two-binary-arrays5142/1

class Solution {
public:
    int longestCommonSum(bool arr1[], bool arr2[], int n) {
            // code here 
          vector<int>diff(n);
          
          for(int i=0;i<n;i++){
              diff[i]=arr1[i]-arr2[i];
          }
          
          unordered_map<int,int>mp;
          
          int sum=0;
          
          int ans=0;
          
          mp[0]=-1;
          
          for(int i=0;i<n;i++){
              sum+=diff[i];
              
              if(sum==0){
                  ans=i+1;
              }
              
              if(mp.find(sum)!=mp.end()){
                  ans=max(ans,i-mp[sum]);
              }else mp[sum]=i;
          }
          
          return ans;
    }
};
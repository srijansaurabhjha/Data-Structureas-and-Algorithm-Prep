//Memoization
#include<bits/stdc++.h>

int f(vector<int>&weight,vector<int>&value,int capacity,int ind,vector<vector<int>>&dp){
    if(ind==0){
        if(weight[0]<=capacity)return value[0];
        else return 0;
    }
    if(dp[ind][capacity]!=-1)return dp[ind][capacity];
    int take=0;
    if(weight[ind]<=capacity){
        take=value[ind]+f(weight,value,capacity-weight[ind],ind-1,dp);
    }
    int notTake=f(weight,value,capacity,ind-1,dp);
    
    return dp[ind][capacity]=max(take,notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,-1));
    return f(weight,value,maxWeight,n-1,dp);
}

//Tabulation 1

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
//     vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,-1));
//     return f(weight,value,maxWeight,n-1,dp);
     vector<vector<int>>dp(n+1,vector<int>(maxWeight+1,0));
    
    // base case
//     for(int j=0;j<=maxWeight;j++){
//         dp[0][j]=(weight[0]<=maxWeight)?value[0]:0;
//     }
    for(int j=weight[0];j<=maxWeight;j++){
        dp[0][j]=value[0];
    }
    
    for(int ind=1;ind<n;ind++){
        for(int cap=0;cap<=maxWeight;cap++){
            int take=0;
            if(weight[ind]<=cap){
                take=value[ind]+dp[ind-1][cap-weight[ind]];
            }
            int notTake=dp[ind-1][cap];
            
            dp[ind][cap]=max(take,notTake);
        }
    }
    
    return dp[n-1][maxWeight];
}
















// Problem Statement

// Let there be N workers and N jobs. Any worker can be assigned to perform any job, incurring some cost that may vary depending on the work-job assignment. It is required to perform all jobs by assigning exactly one worker to each job and exactly one job to each agent in such a way that the total cost of the assignment is minimized.

// Input Format
// Number of workers and job: N
// Cost matrix C with dimension N*N where C(i,j) is the cost incurred on assigning ith Person to jth Job.

// Sample Input
// 4

// [
// 9 2 7 8
// 6 4 3 7
// 5 8 1 8
// 7 6 9 4
// ]

// Sample Output
// 13

// Constraints
// N <= 20

#include<bits/stdc++.h>
using namespace std;
int dp[21][(1LL<<21)];
int C[21][21];

int solve(int i,int mask,int n){
    if(i>=n)return 0;
    if(dp[i][mask]!=-1)return dp[i][mask];
    int minCost=INT_MAX;
    for(int j=0;j<n;j++){
        //If Jth person is available
        if(mask&(1LL<<j)){
            minCost=min(minCost,C[j][i]+solve(i+1,mask^(1<<j),n));
        }
    }
    return dp[i][mask]=minCost;
}

int main(){
     int n;
     cin>>n;

     for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>C[i][j];
        }
     }
     memset(dp,-1,sizeof(dp));

     
     //dp[i][mask]->minimum cost to to assign job from 1 to n.mask represent the set of available
     //peoples with us.
     //If jth bit of mask is present this means j+1th person in part of available person subset
    //final Answer->dp[1][(1<<n)]
    //dp[i][mask]=cji+dp[i+1][mask with jth bit off] -> Try for all valid j(jth bit on) and select the minimum
    int mask=(1LL<<n);
    cout<<solve(0,mask-1,n)<<endl;

return 0;
}














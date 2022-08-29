// "Given a set of cities and distance between every pair of cities, the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point.""Given a set of cities and distance between every pair of cities, the problem is to find the shortest possible route that visits every city exactly once and returns to the starting point."

//Approach
//1. dp[i,{S}]-> minimum distance needed to travel . If we are currently at city i and we need to visit all cities in set {S} and reach back to city 1(starting point).

//2.Recurrence relation-> dp[i][S]=dist[i][j]+dp[j,{S}-j]-> minimum among all valid j
//{S}-> will be represnted by bitmask

//S.C-> (n*2^n)
//T.C->(n^2*2^n)

#include<bits/stdc++.h>
using namespace std;

int dp[22][(1<<22)];
int totalCities=0;

int shortest_path(int current_city,int S,vector<vector<int>>&city,int n){
    //S->set of cities left to travel
    if(S==1){
        return dp[current_city][0]=city[current_city][0];
    }
    if(dp[current_city][S]!=-1)return dp[current_city][S];

    int answer=INT_MAX;
    for(int i=1;i<=n;i++){
        if(S&(1LL<<i)){
            answer=min(answer,city[current_city][i]+shortest_path(i,S^(1LL<<i),city,n));
        }
    }
    return dp[current_city][S]=answer;
}

int main(){
    int n;
    cin>>n;//n->no. of cities
    vector<vector<int>>city(n+1,vector<int>(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>city[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));
    cout<<shortest_path(0,(1LL<<n)-1,city,n);
    return 0;
}
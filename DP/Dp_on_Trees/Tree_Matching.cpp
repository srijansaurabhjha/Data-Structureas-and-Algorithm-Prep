#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(ll node,ll parent,vector<ll>adj[],vector<vector<ll>>&dp){
   for(auto child:adj[node]){
      if(child==parent)continue;
      dfs(child,node,adj,dp);
      dp[node][0]+=max(dp[child][0],dp[child][1]);

   }


   for(auto child:adj[node]){
      if(child==parent)continue;
      dp[node][1]=max(dp[node][1],1+(dp[node][0]-max(dp[child][0],dp[child][1]))+dp[child][0]);
   }

}

void solve(){
   ll n;
   cin>>n;
   vector<ll>adj[n+1];
   vector<vector<ll>>dp(n+1,vector<ll>(2,0));

   for(ll i=0;i<n-1;i++){
      ll u,v;
      cin>>u>>v;
      adj[u].push_back(v);
      adj[v].push_back(u);
   }
   
   dfs(1,-1,adj,dp);
   cout<<max(dp[1][0],dp[1][1])<<endl;
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    solve();
    return 0;
}
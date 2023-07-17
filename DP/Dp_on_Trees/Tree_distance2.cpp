#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(ll node,ll parent,vector<ll>adj[],vector<ll>&node_in_subtree,vector<ll>&subTreeAns){
    ll noOfNodes=0;
    ll ansOfSubtree=0;
    for(auto& child:adj[node]){
        if(child==parent)continue;
        dfs(child,node,adj,node_in_subtree,subTreeAns);
        noOfNodes+=node_in_subtree[child];
        ansOfSubtree+=subTreeAns[child]+node_in_subtree[child];
    }
    node_in_subtree[node]=1+noOfNodes;
    subTreeAns[node]=ansOfSubtree;
}

void dfs_solve(ll node,ll parent,ll partial_ans,vector<ll>adj[],vector<ll>&node_in_subtree,vector<ll>&subTreeAns,vector<ll>&ans,ll TotalNodes){
    
    ans[node]=subTreeAns[node]+partial_ans+(TotalNodes-node_in_subtree[node]);

    for(auto& child:adj[node]){
        if(child==parent)continue;
        ll newPartial_ans=ans[node]-(subTreeAns[child]+node_in_subtree[child]);
        dfs_solve(child,node,newPartial_ans,adj,node_in_subtree,subTreeAns,ans,TotalNodes);
    }
}

void solve(){
    ll n;
    cin>>n;
    vector<ll>adj[n+1];
    vector<ll>nodes_in_subtree(n+1,0);
    vector<ll>subTreeAns(n+1,0);
    vector<ll>ans(n+1,0);

    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,-1,adj,nodes_in_subtree,subTreeAns);
    dfs_solve(1,-1,0,adj,nodes_in_subtree,subTreeAns,ans,n);
    for(ll i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(ll node,vector<ll>adj[],vector<ll>&depth,ll parent=-1){
    for(auto& child:adj[node]){
        if(child==parent)continue;
        depth[child]=depth[node]+1;
        dfs(child,adj,depth,node);
    }
}

void solve(){
    ll n;
    cin>>n;
    vector<ll>adj[n+1];
    for(ll i=0;i<n-1;i++){
        ll u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll>depth(n+1,0);

    dfs(1,adj,depth);

    ll max_depth=INT_MIN;
    ll max_depth_node=1;

    for(ll i=1;i<=n;i++){
        if(max_depth<depth[i]){
            max_depth=depth[i];
            max_depth_node=i;
        }
    }

    for(ll i=1;i<=n;i++){
        depth[i]=0;
    }

    dfs(max_depth_node,adj,depth);

    max_depth=INT_MIN;
    for(ll i=1;i<=n;i++){
        if(max_depth<depth[i]){
            max_depth=depth[i];
        }
    }
    cout<<max_depth<<endl;
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
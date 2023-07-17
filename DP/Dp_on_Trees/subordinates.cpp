#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N=3e5;

ll sub[N]={0}; 

void dfs(ll node,ll parent,vector<ll>adj[]){
    ll sub_ordinates=0;
    for(auto& child:adj[node]){
        if(child==parent)continue;

        dfs(child,node,adj);
        sub_ordinates+=(1+sub[child]);
    }
    sub[node]=sub_ordinates;
}

void solve(){
    ll n;    
    cin>>n;
    vector<ll>adj[n+1];

    for(ll i=2;i<=n;i++){
        ll boss;
        cin>>boss;
        adj[boss].push_back(i);
    }
    
    dfs(1,-1,adj);

    for(ll i=1;i<=n;i++){
        cout<<sub[i]<<" ";
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
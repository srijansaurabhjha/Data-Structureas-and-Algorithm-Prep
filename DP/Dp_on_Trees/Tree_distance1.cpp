#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs_depth(ll node,ll par,vector<ll>adj[],vector<ll>&depth){
     ll node_depth=0;
     for(auto& child:adj[node]){
         if(child!=par){
             dfs_depth(child,node,adj,depth);
             node_depth=max(node_depth,1+depth[child]);
         }
     }
     depth[node]=node_depth;
}


void dfs_solve(ll node,ll parent,ll partial_ans,vector<ll>adj[],vector<ll>&depth,vector<ll>&ans){
    vector<ll>prefixMax;
    vector<ll>suffixMax;

    //filling prefix and suffix arrays
    for(auto& child:adj[node]){
        if(child!=parent){
            prefixMax.push_back(depth[child]);
            suffixMax.push_back(depth[child]);
        }
    }

    //Building prefix and suffix arrays
    for(ll i=1;i<(ll)prefixMax.size();i++){
         prefixMax[i]=max(prefixMax[i],prefixMax[i-1]);
    }

    for(ll i=(ll)suffixMax.size()-2;i>=0;i--){
        suffixMax[i]=max(suffixMax[i],suffixMax[i+1]);
    }

    ll sz=suffixMax.size()-1;

    //evaluating partial_ans for each child node
    ll child_no=0;
    for(auto child:adj[node]){
        if(child!=parent){
            ll opt1=((child_no==0)?INT_MIN:prefixMax[child_no-1]);
            ll opt2=((child_no==sz)?INT_MIN:suffixMax[child_no+1]);
            ll new_partial_ans=1+max(partial_ans,max(opt1,opt2));
            dfs_solve(child,node,new_partial_ans,adj,depth,ans);
            child_no++;
        }
    }

    //evaluating answer for node
    ans[node]=max(depth[node],1+partial_ans);
}

void solve(){
    ll n;
    cin>>n;
    vector<ll>adj[n+1];
    vector<ll>depth(n+1,0);
    vector<ll>ans(n+1,0);
    for(ll i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs_depth(1,-1,adj,depth);
    dfs_solve(1,-1,-1,adj,depth,ans);

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
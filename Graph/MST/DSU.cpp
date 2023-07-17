#include <bits/stdc++.h>
using namespace std;

#define ll long long

//Implementing Dosjoint set data structure
class DSU{
    vector<int>parent,rank,size;
public:
    DSU(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    //find Ultimate Parent
    int findUpar(int u){
        if(u==parent[u])return u;

        return parent[u]=findUpar(parent[u]);
    }

    void unionByRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)return;

        if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }

    void unionBySize(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if(ulp_u==ulp_v)return;

        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }else{
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};

void solve(){
    cout<<"Union By Rank"<<endl;
    DSU ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    //Now let's check weather 3 and 7 are in same component or not
    cout<<ds.findUpar(3)<<" "<<ds.findUpar(7)<<"  ";
    if(ds.findUpar(3)==ds.findUpar(7)){
         cout<<"Belong to same component"<<endl;
    }else{
        cout<<"Does not belong to same component"<<endl;
    }

    ds.unionByRank(3,7);

    cout<<ds.findUpar(3)<<" "<<ds.findUpar(7)<<"  ";
    if(ds.findUpar(3)==ds.findUpar(7)){
         cout<<"Belong to same component"<<endl;
    }else{
        cout<<"Does not belong to same component"<<endl;
    }

    cout<<endl;

    cout<<"Union By size"<<endl;
    DSU ds2(7);
    ds2.unionBySize(1,2);
    ds2.unionBySize(2,3);
    ds2.unionBySize(4,5);
    ds2.unionBySize(6,7);
    ds2.unionBySize(5,6);    

    //Now let's check weather 3 and 7 are in same component or not
    cout<<ds2.findUpar(3)<<" "<<ds2.findUpar(7)<<"  ";
    if(ds2.findUpar(3)==ds2.findUpar(7)){
         cout<<"Belong to same component"<<endl;
    }else{
        cout<<"Does not belong to same component"<<endl;
    }

    ds2.unionBySize(3,7);

    cout<<ds2.findUpar(3)<<" "<<ds2.findUpar(7)<<"  ";
    if(ds2.findUpar(3)==ds2.findUpar(7)){
         cout<<"Belong to same component"<<endl;
    }else{
        cout<<"Does not belong to same component"<<endl;
    }
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
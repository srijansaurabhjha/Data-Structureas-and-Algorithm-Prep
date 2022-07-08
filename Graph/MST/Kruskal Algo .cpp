// https://www.interviewbit.com/problems/commutable-islands/

int find(int v,vector<int>&parent){
    
    if(v==parent[v])return v;
    
    return parent[v]=find(parent[v],parent);
}

void union_set(int a,int b,vector<int>&parent,vector<int>&size){
    a=find(a,parent);
    b=find(b,parent);
    
    if(a!=b){
        if(size[a]<size[b])swap(a,b);
        
        parent[b]=a;
        
        size[a]+=size[b];
    }
}


int Solution::solve(int A, vector<vector<int> > &B) {
    
    vector<pair<int,pair<int,int>>>g(A+1);
    
    for(int i=0;i<B.size();i++){
        g.push_back({B[i][2],{B[i][0],B[i][1]}});
    }
    
    int minCost=0;
    
    vector<int>parent(A+1);
    vector<int>size(A+1);
    
    for(int i=1;i<=A;i++){
        parent[i]=i;
        size[i]=1;
    }

    sort(g.begin(),g.end());
    
    for(auto edge:g){
       auto [wt,nodes]=edge;
       auto [u,v]=nodes;
    
        //  int u=edge.second.first;
        //  int v=edge.second.second;
        //  int wt=edge.first;
        if(find(u,parent)!=find(v,parent)){
            minCost+=wt;
            union_set(u,v,parent,size);
        }
    }
    
    return minCost;
}

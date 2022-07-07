class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>>g[n+1];          //first=destinstion second=weight
        for(int i=0;i<times.size();i++){
            g[times[i][0]].push_back({times[i][1],times[i][2]});   
        }
        
        vector<int>dist(n+1,1e9);
        
        //min Heap
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;//first->dist //second->vertex
        
        dist[k]=0;
        
        pq.push({dist[k],k});
        bool vis[n+1];
        memset(vis,false,sizeof(vis));
        
        while(!pq.empty()){ 
            pair<int,int>temp=pq.top();
            pq.pop();
            int u=temp.second;
            vis[u]=true;
            for(auto child:g[u]){
                int v=child.first;
                int wt=child.second;
                if(vis[v]==false&&dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
        
        int ans=0;
        for(int i=1;i<dist.size();i++){
            ans=max(ans,dist[i]);
        }
        
        if(ans==1e9)return -1;
        
        return ans;
    }
};
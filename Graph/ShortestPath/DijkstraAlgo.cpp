//using Priority queue
#include<bits/stdc++.h>

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source) 
{
    unordered_map<int,list<pair<int,int>>>g;
    // Create an adjacency list.
    for (int i = 0; i < edge.size(); i++) 
    {
        g[edge[i][0]].push_back({edge[i][1], edge[i][2]});
        g[edge[i][1]].push_back({edge[i][0], edge[i][2]});
    }

    return dijkstraHelper(g, vertices,source);
}

vector<int> dijkstraHelper(unordered_map<int,list<pair<int,int>>>&g,int vertices, int source) 
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> dist(vertices, INT_MAX);
    
    // Push the source vertex in the priority queue.
    dist[source]=0;
    pq.push({dist[source], source});
    
    vector<bool> visited(vertices, false);
    
    // Loop till all vertices are visited.
    while (!pq.empty()) 
    {
        auto top=pq.top();
        int u =top.second;
        
        pq.pop();
        
        visited[u] = true;
        
        // Update the distances of the adjacent nodes.
        for (auto child:g[u]) 
        {
            int v = child.first;
            int wt = child.second;

            if (visited[v] == false && dist[v] > dist[u] + wt) 
            {
                dist[v] = dist[u] + wt;
                
                pq.push({dist[v], v});
            }
        }
        
    }

    return dist;
}




//Using set
#include<unordered_map>
#include<list>
#include<set>

vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source) 
{
	// Write your code here
	// 'edge' contains {u, v, distance} vectors

	// Return a vector of size 'vertices' denoting 
	// distances of source node to every node
    
    unordered_map<int,list<pair<int,int>>>g;
    
    for(auto e:edge){
        int u=e[0];
        int v=e[1];
        int wt=e[2];
        g[u].push_back({v,wt});
        g[v].push_back({u,wt});
    }
    
    set<pair<int,int>>s;
    vector<int>dist(vertices,INT_MAX);
    dist[source]=0;
    s.insert({dist[source],source});
    
    while(!s.empty()){
        auto top=*(s.begin());
        int u=top.second;
        s.erase(s.begin());
        for(auto child:g[u]){
            int v=child.first;
            int wt=child.second;
            if(dist[v]>dist[u]+wt){
                if(s.find({dist[v],v})!=s.end())s.erase(s.find({dist[v],v}));
                dist[v]=dist[u]+wt;
                s.insert({dist[v],v});
            }
        }
    }
    
    return dist;
}




















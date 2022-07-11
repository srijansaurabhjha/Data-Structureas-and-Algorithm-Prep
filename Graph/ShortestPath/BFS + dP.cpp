// https://leetcode.com/contest/weekly-contest-295/problems/minimum-obstacle-removal-to-reach-corner/

class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    
    
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int m=grid.size();
        int n=grid[0].size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1,1e9));
        
        queue<pair<int,int>>q;
        
        q.push({0,0});
        dp[0][0]=0;
        
        while(!q.empty()){
            auto Top=q.front();
            q.pop();
            
            int r=Top.first;
            int c=Top.second;
            
            for(int i=0;i<4;i++){
                int newr=r+dx[i];
                int newc=c+dy[i];
                
                if(newr>=0&&newc>=0&&newr<m&&newc<n&&grid[newr][newc]+dp[r][c]<dp[newr][newc]){
                    dp[newr][newc]=grid[newr][newc]+dp[r][c];
                    q.push({newr,newc});
                }
            }
            
        }
        
        return dp[m-1][n-1];
    }
};













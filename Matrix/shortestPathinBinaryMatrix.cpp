
class points{
  
    public:
    int x;    // x coordinate
    int y;    // y coordinate
    int len; // No. of cells included in the path
    
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]==1)return -1;
        
        int n=grid.size();
        
        int dx[8] = {1,0,-1,0,1,-1,1,-1};
        int dy[8] = {0,1,0,-1,1,-1,-1,1};
        
        queue<points>q;
        q.push({0,0,1}); 
        grid[0][0]=1; //marking node visited
        
        
        while(!q.empty()){
            int size=q.size();
            
            while(size--){
                points p=q.front();
                q.pop();
                
                //checking if we have found answer 
                if(p.x==n-1&&p.y==n-1)return p.len;
                
                //Traverse in All 8 direction
                for(int i=0;i<8;i++){
                    int r=p.x+dx[i];
                    int c=p.y+dy[i];
                    
                    if(r>=0&&c>=0&&r<n&&c<n&&grid[r][c]==0){
                        q.push({r,c,p.len+1});
                        //marking as visited
                        grid[r][c]=1;
                    }
                }
                
            }
        }
        
        return -1;
    }
};
// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int L=0,R=matrix[0].size()-1;
        int T=0,B=matrix.size()-1;
        
        vector<int>ans;
        
        while(L<=R&&T<=B){
            //Top Row
            for(int j=L;j<=R;j++){
                ans.push_back(matrix[T][j]);
            }
            T++;
            
            //Right Col
            for(int i=T;i<=B;i++){
                ans.push_back(matrix[i][R]);
            }
            R--;
            
            if(L>R||T>B)break;
            
            //Bottom Row
            for(int j=R;j>=L;j--){
                ans.push_back(matrix[B][j]);
            }
            B--;
            
            //Left Col
            for(int i=B;i>=T;i--){
                ans.push_back(matrix[i][L]);
            }
            L++;
            
        }
        
        return ans;
    }
};
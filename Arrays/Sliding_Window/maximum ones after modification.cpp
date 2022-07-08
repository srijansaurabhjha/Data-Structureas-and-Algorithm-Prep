// https://www.interviewbit.com/problems/maximum-ones-after-modification/

int Solution::solve(vector<int> &A, int B) {
    
    int i=0;
    int j=0;
    
    int count=0;
    int max_Len=0;
    
    while(j<A.size()){
        
        //expanding window
        if(A[j]==0&&count<B){
            j++;
            count++;
        }
        else if(A[j]==0&&count==B){
            
            if(A[i]==0){
                count--;
            }
            
            if(i!=j)i++;
            
        }else if(A[j]==1)j++;
        
        max_Len=max(max_Len,j-i);
    }
    
    return max_Len;
}


//2nd Way
    
int Solution::solve(vector<int> &A, int B) {
    
    int i=0;
    int j=0;

    int max_Len=0;
    
    while(j<A.size()){
        
        if(A[j]==0)B--;
        
        while(B<0){
            if(A[i]==0)B++;
            i++;
        }
        max_Len=max(max_Len,j-i+1);
        j++;
    }
    
    return max_Len;
}

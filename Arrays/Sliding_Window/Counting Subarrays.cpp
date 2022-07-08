// https://www.interviewbit.com/problems/counting-subarrays/

int Solution::solve(vector<int> &A, int B) {
    
    int sum=0;
    
    int i=0;
    int j=0;
    int count=0;
    while(j<A.size()){
        
        sum+=A[j];
        
        while(sum>=B){
            sum-=A[i];
            i++;
        }
        
        count+=j-i+1;
        
        j++;
    }
    
    return count;   
}













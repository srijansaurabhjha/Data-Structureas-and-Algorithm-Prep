// https://www.interviewbit.com/problems/reverse-bits/

unsigned int Solution::reverse(unsigned int A) {
    
    unsigned int ans=0;
    
    for(int i=31;i>=0;i--){
        
        if(A&1){
            
            ans=ans+(1<<i);
            
        }
        
        A=A>>1;
        
    }
    
    return ans;
}

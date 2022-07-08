// https://www.interviewbit.com/problems/array-3-pointers/

int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    int i=0,j=0,k=0;

//I want to find the 3 close values such that abs is minimum
    int ans=INT_MAX;
    while(i<A.size()&&j<B.size()&&k<C.size()){
        
        int minimum=min(A[i],min(B[j],C[k]));
        
        int possibleAns=max(A[i],max(B[j],C[k]))-minimum;
        
        if(minimum==A[i])i++;
        else if(minimum==B[j])j++;
        else k++;
        
        ans=min(ans,possibleAns);
    }
    
    return ans;
}


// ans-> minimize(max(A,B,C)-min(A,B,C));

// try to maximize the 2nd term
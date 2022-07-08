// https://www.interviewbit.com/problems/container-with-most-water/

int Solution::maxArea(vector<int> &A) {

// Brute Force Approach ->O(n^2)    
    // int res=0;
    
    // for(int l=0;l<A.size();l++){
    //     for(int r=l+1;r<A.size();r++){
    //         int Area=(r-l)*min(A[l],A[r]);
    //         res=max(res,Area);
    //     }
    // }
    
    // return res;
    
///////////////////////////

    int l=0;
    int r=A.size()-1;
    
    int res=0;
    
    while(l<r){
        int Area=(r-l)*min(A[l],A[r]);
        res=max(res,Area);
        
        if(A[l]<A[r])l++;
        else r--;
    }
    
    return res;
}


// coord->(i,A[i])
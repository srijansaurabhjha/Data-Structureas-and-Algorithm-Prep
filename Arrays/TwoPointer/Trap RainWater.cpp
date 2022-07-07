// https://www.interviewbit.com/problems/rain-water-trapped/

int Solution::trap(const vector<int> &A) {
    
    if(A.size()==0)return 0;
    
    int l=0;
    int r=A.size()-1;
    int maxL=A[l],maxR=A[r];
    int ans=0;
    while(l<r){
        
        if(maxL>=maxR){
            r--;
            maxR=max(maxR,A[r]);
            ans+=maxR-A[r];
        }else{
            l++;
            maxL=max(maxL,A[l]);
            ans+=maxL-A[l];
        }
    }
    
    return ans;
}


// trap[i]=min(maxLeftHEight,maxRightheight)-height[i]

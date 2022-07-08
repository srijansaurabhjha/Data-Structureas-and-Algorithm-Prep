// https://www.interviewbit.com/problems/intersection-of-sorted-arrays/

vector<int> Solution::intersect(const vector<int> &A, const vector<int> &B) {
    
    int m=A.size();
    int n=B.size();
    
    vector<int>ans;
    
    int i=0,j=0;
    
    while(i<m&&j<n){
        
        if(A[i]==B[j]){
            ans.push_back(A[i]);
            i++;
            j++;
        }else if(A[i]>B[j]) j++;
        else i++;
        
    }
    
    return ans;
}

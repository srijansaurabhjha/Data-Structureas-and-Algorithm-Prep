// https://www.interviewbit.com/problems/3-sum/

int Solution::threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    long long ans=INT_MAX;
    for(int i=0;i<A.size();i++){
        
        int l=i+1,r=A.size()-1;
        
        while(l<r){
            long long sum=A[i]+A[l]+A[r];
            
            if(abs(B-ans)>abs(B-sum))ans=sum;
            
            if(sum>B)r--;
            else l++;
        }
    }
    
    return ans;
}

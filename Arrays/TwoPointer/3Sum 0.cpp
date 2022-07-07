// https://www.interviewbit.com/problems/3-sum-zero/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    vector<vector<int>>ans;
    sort(A.begin(),A.end());
    
    for(int i=0;i<A.size();i++){
        int l=i+1,r=A.size()-1;
        
        while(l<r){
            long long int sum=(long long int)A[i]+(long long int)A[l]+(long long int)A[r];
            
            if(sum==0){
                ans.push_back({A[i],A[l],A[r]});
                
                int f=A[l];
                int b=A[r];
                
                while(l<r&&A[l]==f)l++;
                while(l<r&&A[r]==b)r--;
            }
            else if(sum>0)r--;
            else l++;
        }
        
        while(i+1<A.size()&&A[i]==A[i+1])i++;
    }
    
    return ans;
}

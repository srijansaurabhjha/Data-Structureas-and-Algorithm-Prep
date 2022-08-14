class Solution {
public:
    
    int helper(int i,int bucket,int currSum,vector<int>&nums,int k,int reqSum,vector<int>&vis){
        
        int n=nums.size();
        
        if(bucket+1==k)return 1;

        
        if(currSum==reqSum){
            return helper(0,bucket+1,0,nums,k,reqSum,vis);
        }
                
        
        if(i>=n){
            return 0;
        }
        
        if(currSum>reqSum){
            return 0;
        }
        
        for(int j=i; j<nums.size(); j++){
            if(!vis[j]){
                
                vis[j]=true;
                currSum+=nums[j];
                
                if(helper(j+1,bucket,currSum,nums,k,reqSum,vis)){
                    return true;
                }
                
                vis[j]=false;
                currSum-=nums[j];
                
				//OPTIMIZATION TO AVOID TLE
                if(currSum==0)
                    break;
            }
        }
        
        return false;

    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%k!=0)return false;
        
        int reqSum=sum/k;
        //Required Bucket=k
        vector<int>vis(nums.size(),0);
        sort(nums.begin(),nums.end());
        return helper(0,0,0,nums,k,reqSum,vis);
    }
};
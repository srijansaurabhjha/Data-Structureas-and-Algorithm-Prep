class Solution {
public:
    vector<vector<int>>ans;
    
    //i->current element that is fixed
    
    void helper(vector<int>&nums,int i){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int j=i;j<nums.size();j++){
            swap(nums[j],nums[i]);
            helper(nums,i+1);
            swap(nums[j],nums[i]);
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        helper(nums,0);
        return ans;
    }
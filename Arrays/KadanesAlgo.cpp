// https://leetcode.com/contest/weekly-contest-299/problems/maximum-score-of-spliced-array/

class Solution {
public:
    
    int maxSubArraySum(vector<int>&arr){
        int osum=INT_MIN;
        int csum=0;
        for(int i=0;i<arr.size();i++){
            
            if(csum>0){
                csum+=arr[i];
            }else{
                csum=arr[i];
            }
            
            osum=max(osum,csum);
        }
        return osum;
    }
    
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int>diff1(nums2.size()); // stores nums2[i]-nums1[i];
        vector<int>diff2(nums1.size()); // stores nums1[i]-nums2[i];
        
        int Sum1=0;
        int Sum2=0;
        for(int i=0;i<nums1.size();i++){
            Sum1+=nums1[i];
            Sum2+=nums2[i];
            diff1[i]=nums2[i]-nums1[i];
            diff2[i]=nums1[i]-nums2[i];
        }
        
        int res1=Sum1+maxSubArraySum(diff1);
        int res2=Sum2+maxSubArraySum(diff2);
        
        int ans=max(res1,res2);
        
        return ans;
    }
};
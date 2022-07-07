// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        vector<int>sol;
        
        deque<int>dq;    //Store indices
        
        int s=0,e=0;
        
        while(e<n){
            
            //Pop smaller values from deque
            while(!dq.empty()&&nums[dq.back()]<nums[e]){
                dq.pop_back();
            }
            
            //Append the new value
            dq.push_back(e);
            
            //Remove and discard leftmost value from window
            if(s>dq.front()){
                dq.pop_front();
            }
            
            //Check the condition in which 1st window is not yet hit
            if(e+1>=k){
                sol.push_back(nums[dq.front()]);
                s++;
            }
            
            e++;
        }
        
        return sol;
    }
    
};


// T.C->O(N)
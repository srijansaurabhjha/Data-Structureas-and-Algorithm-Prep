/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {
    
    if(!A)return {};
    
    map<int,vector<int>>mp;
    
    vector<vector<int>>ans;
    
    queue<pair<TreeNode*,int>>q;
    
    q.push({A,0});
    
    while(!q.empty()){
        TreeNode*curr=q.front().first;
        int hd=q.front().second;
        
        q.pop();
        
        if(mp.find(hd)!=mp.end()){
            mp[hd].push_back(curr->val);
        }else{
            vector<int>temp;
            temp.push_back(curr->val);
            mp[hd]=temp;
        }
        
        if(curr->left)q.push({curr->left,hd-1});
        if(curr->right)q.push({curr->right,hd+1});
        
    }
    
    for(auto x:mp){
        ans.push_back(x.second);
    }
    
    return ans;
}

// https://www.interviewbit.com/problems/vertical-order-traversal-of-binary-tree/
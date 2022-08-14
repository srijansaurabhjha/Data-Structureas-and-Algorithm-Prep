#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsequences(vector<int> nums, int index, int size)
{
    if (index == size)
    {
        vector<vector<int>> s;
        return s;
    }

    vector<vector<int>> small = subsequences(nums, index + 1, size);
    vector<vector<int>>ans;
    for (int i = 0; i < small.size(); i++)
    {
        vector<int> temp;

        for(auto x:small){
            temp.push_back(nums[index]);
        }

        ans.push_back(temp);
    }

    return small;
}


int main(){

    vector<int>nums={1,2,3,4};

    vector<vector<int>>ans=subsequences(nums,0,4);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
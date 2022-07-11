#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&nums){
    

    unordered_map<int,int>mp;

    for(auto x:nums)mp[x]++;

    set<int>s(nums.begin(),nums.end());
    nums.assign(s.begin(),s.end());
}

int main(){
vector<int>nums={2,3,3,5,6,6};

cout<<f(nums);

return 0;
}
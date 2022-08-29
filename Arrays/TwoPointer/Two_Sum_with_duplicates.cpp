#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1, 1, 2, 45, 46, 46};
    int Target = 47;
    
    int count=0;

    unordered_set<int>s1;
    unordered_set<int>seen;
    
    for(int i=0;i<nums.size();i++){
        int need=Target-nums[i];
        if(s1.find(need)!=s1.end()){
            
        }
    }

    return 0;
}
// https://leetcode.com/contest/weekly-contest-299/problems/count-number-of-ways-to-place-houses/

class Solution {
public:
    int m;
    
    long long Mod(long long x){
        return (((x%m)+m)%m);
    }
    
    int countHousePlacements(int n) {
        
        if(n==1)return 4;
        
        m=1e9+7;
        
        vector<int>dp(n+1,0);
        
        dp[1]=2;
        dp[2]=3;
        
        for(int i=3;i<=n;i++){
          dp[i]=Mod(Mod(dp[i-1])+Mod(dp[i-2]));
        }
        
        return Mod(Mod(dp[n])*Mod(dp[n]));
    }
};
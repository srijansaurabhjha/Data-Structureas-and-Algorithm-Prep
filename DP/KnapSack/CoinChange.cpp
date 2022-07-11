// Return the fewest number of coins to make up the amount

#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&c,int amount){
    vector<int>dp(amount+1,amount+1);

    dp[0]=0;

    for(int i=0;i<=amount;i++){
        for(int coin:c){
            if(i-coin>=0)dp[i]=min(dp[i],dp[i-coin]+1);
        }
    }

    return dp[amount]==amount+1?-1:dp[amount];
}


int main(){
   
   vector<int>c={1,2,5};
   int amount=11;

   cout<<f(c,amount);

return 0;
}
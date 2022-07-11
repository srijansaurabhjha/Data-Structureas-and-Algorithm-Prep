#include<bits/stdc++.h>
using namespace std;

int f(vector<int>&h){
    int rob1=0;//previous day robbery
    int rob2=0;//previous to previous day robbery

    for(int i=0;i<h.size();i++){
        int Max_Rob_Possible_Till_That_Day=max(rob1,rob2+h[i]);
        rob2=rob1;
        rob1=Max_Rob_Possible_Till_That_Day;
    }

    return rob1;
}

int main(){

   vector<int>houses={1,2,3,1};

   cout<<f(houses);

return 0;
}
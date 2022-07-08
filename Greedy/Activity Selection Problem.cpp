// https://www.codingninjas.com/codestudio/problems/maximum-activities_1062712

#include<bits/stdc++.h>

class activity{
   public:
    int s;
    int e;
};

bool cmp(activity a,activity b){
    return a.e<b.e;
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n=start.size();
    
    activity a[n];
    for(int i=0;i<n;i++){
        a[i].s=start[i];
        a[i].e=finish[i];
    }
    
    sort(a,a+n,cmp);
     int lastEnd=a[0].e;
    int cnt=1;
    for(int i=1;i<n;i++){
       if(lastEnd<=a[i].s){
           cnt++;
           lastEnd=a[i].e;
       }
    }
    
    return cnt;
}


















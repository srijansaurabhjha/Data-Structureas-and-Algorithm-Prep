//Sort the utem as per value/weight

// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1/

#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


bool Comp(Item a ,Item b){
    
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    
    return r1>r2;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,Comp);
        
        
        int currW=0;
        double maxVal=0;
        
        for(int i=0;i<n;i++){
            
            if(currW+arr[i].weight<=W){
                maxVal+=(double)arr[i].value;
                currW+=arr[i].weight;
            }else{
                int rem=W-currW;
                maxVal+=((double)rem*((double)arr[i].value/arr[i].weight));
                break;
            }
        }
        
        return maxVal;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
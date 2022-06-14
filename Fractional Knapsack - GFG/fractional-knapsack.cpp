// { Driver Code Starts
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


class Solution
{
    public:
    bool static compare(Item a,Item b)
    {
        double p=(double)a.value/(double)a.weight;
        double q=(double)b.value/(double)b.weight;
        return p>q;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans=0.0;
        int w=0;
        sort(arr,arr+n,compare);
        for(int i=0;i<n;i++)
        {
            if(w + arr[i].weight <=W)
            {
                ans+=arr[i].value;
                w+=arr[i].weight;
            }
            else
            {
                int remaining=W-w;
                double val=(arr[i].value /(double)arr[i].weight)*(double)remaining;
                ans+=val;
                
                break;
            }
        }
        return ans;
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
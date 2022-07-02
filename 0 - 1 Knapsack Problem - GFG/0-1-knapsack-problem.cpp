// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> curr(W+1);
       
       for(int w=wt[0] ; w<=W ; w++)
       {
           curr[w]=val[0];
       }
       
       for(int index=1; index<n ; index++)
       {
           for(int w=W; w>=0 ; w--)
           {
               int inc=0;
               if(wt[index] <=w )
                inc=val[index] + curr[w - wt[index]];
                
                int exc=curr[w];
                
                curr[w]=max(inc,exc);
           }
       }
       return curr[W];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
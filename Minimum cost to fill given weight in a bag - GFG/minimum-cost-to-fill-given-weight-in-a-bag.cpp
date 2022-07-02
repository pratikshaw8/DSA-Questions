// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int helper(int cost[],int n, int W,vector<vector<int>>& dp)
	{
	    if(W==0)
	    return 0;
	    if(n==0 or W<0)
	    return INT_MAX;
	    
	    if(dp[n][W]!=-1) return dp[n][W];

	    if(cost[n-1]!=-1 and W-n>=0)
	        return dp[n][W]=min(cost[n-1] + helper(cost,n,W-n,dp),helper(cost,n-1,W,dp));
	    
	    return dp[n][W]= helper(cost,n-1,W,dp);
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        
        /*
        vector<vector<int>> dp1(N+1,vector<int>(W+1,-1));
        int ans=helper(cost,N,W,dp1);
        if(ans==INT_MAX)
        return -1;
        return ans;
        */
        
        vector<int> dp(W+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=W;i++)
        {
            for(int j=0; j<N and j<i ; j++)
            {
                if(dp[i-j-1]==-1 or cost[j]==-1) continue;
                
                dp[i]= min(dp[i],dp[i-j-1]+cost[j]);
            }
            if(dp[i]==INT_MAX)
            dp[i]=-1;
        }
        return dp[W];
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
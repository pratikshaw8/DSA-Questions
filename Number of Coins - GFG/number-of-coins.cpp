// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int tabulation(int coins[],int m,int n)
	{
	    vector<int>dp(n+1,INT_MAX);
	    
	    dp[0]=0;
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(i-coins[j] >=0 and dp[i-coins[j]]!=INT_MAX)
	            dp[i]=min(dp[i], 1+ dp[i-coins[j]]);
	            
	            
	        }
	    }
	    if(dp[n]==INT_MAX)
	    return -1;
	    return dp[n];
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    return tabulation(coins,M,V);
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solve(int n, vector<int> &dp)
	{
	    if(n<=0)
	    return 0;
	    if(dp[n]!=-1) return dp[n];
	    
	    dp[n]=INT_MAX;
	    for(int i=1; i*i <=n ;i++)
	    {
	        dp[n]=min(1+ solve(n-(i*i) ,dp),dp[n]);
	    }
	    return dp[n];
	}
	int tabulation(int n)
	{
	    vector<int> dp(n+1,INT_MAX);
	    dp[0]=0;
	    dp[1]=1;
	    for(int i=2 ;i<=n;i++)
	    {
	        for(int j=1; j*j<=i ;j++)
	        {
	            dp[i]= min(dp[i] , 1+ dp[i-j*j]);
	        }
	    }
	    return dp[n];
	}
	int MinSquares(int n)
	{
	    // Code here
	    /*
	    vector<int> dp(n+1,-1);
	    return solve(n,dp);
	    */
	    return tabulation(n);
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
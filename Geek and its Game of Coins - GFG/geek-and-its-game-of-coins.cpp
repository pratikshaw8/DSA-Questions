// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int solve(int n,int x,int y,int flag , vector<int> dp)
	{
	    if(n<=1)
	    return n;
	    
	    
	    if(dp[n]!=-1) return dp[n];
	    
	    
	    
	    int ans1= solve(n-x,x,y,flag,dp);
	    int ans2= solve(n-y,x,y,flag,dp);
	    int ans3= solve(n-1,x,y,flag,dp);
	    
	    return dp[n]= !(ans1 and ans2 and ans3);
	}
	int tabulation(int n,int x,int y)
	{
	    vector<int> dp(n+1);
	    dp[0]=false;
	    dp[1]=true;
	    
	    for(int i=2;i<=n;i++)
	    {
	        if(i-1>=0 and dp[i-1]==false)
	        dp[i]=true;
	        else if(i-x>=0 and dp[i-x]==false)
	        dp[i]=true;
	        else if(i-y>=0 and dp[i-y]==false)
	        dp[i]=true;
	        else
	        dp[i]=false;
	    }
	    return dp[n];
	}
	int findWinner(int N, int X, int Y)
	{
		// Your code goes here
		/*
		vector<int> dp(N+1,-1);
		int ans1=solve(N,X,Y,-1,dp);
		return ans1 ;
		*/
		
		return tabulation(N,X,Y);
	}

};
	

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
       	int n, x, y;
       	cin >> n >> x >> y;

       

        Solution ob;
        cout << ob.findWinner(n, x, y);
	    cout << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
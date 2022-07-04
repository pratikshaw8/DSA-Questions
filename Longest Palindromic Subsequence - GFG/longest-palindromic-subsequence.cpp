// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
    int solve(string A,int i,int j, vector<vector<int>>& dp)
    {
        if(j>=A.length() or i>j)
        return 0;
        if(i==j) return 1;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(A[i] == A[j])
        {
            return dp[i][j]= 2 + solve(A,i+1,j-1,dp); 
        }
        else
        return dp[i][j]= max(solve(A,i+1,j,dp) , solve(A,i,j-1,dp));
    }
    int tabulation(string A)
    {
        int n=A.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        string temp=A;
        reverse(temp.begin(),temp.end());
        
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=0;
            dp[0][i]=0;
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(A[i-1]==temp[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][n];
        
    }
    int longestPalinSubseq(string A) {
        //code here
        return tabulation(A);
        int n=A.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(A,0,n-1,dp);
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends
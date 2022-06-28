// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod=1e9+7;
    int solve(int n,int r,vector<vector<int>>& dp)
    {
        if(n<r)
        return 0;
        
        if(n==r)
        return 1;
        if(r==1)
        return n%mod;
        
        if(dp[n][r]!=-1)
        return dp[n][r]%mod;
        
        return dp[n][r]=(solve(n-1,r,dp) +solve(n-1,r-1,dp))%mod;
    }
    int tabulation(int n, int r)
    {
        if(r>n) return 0;
        if(r==0) return 1;
        
         vector<vector<int>> dp(r+1,vector<int>(n+1,0));
        
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=1;
            
        }
        
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=(dp[i][j-1]+ dp[i-1][j-1])%mod;
            }
        }
        return dp[r][n];
        


        
    }
    int nCr(int n, int r){
        // code here
        vector<vector<int>> dp(n+1, vector<int>(r+1,-1));
        
        return tabulation(n,r);
        return solve(n,r,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  // } Driver Code Ends
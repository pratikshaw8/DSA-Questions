// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int solve(string& s,string& t, int m,int n,  vector<vector<int>> &dp)
    {
        if(m==0 or n==0)
        return max(m,n);
        
        if(dp[m][n]!=-1)
        return dp[m][n];
        
        if(s[m-1]==t[n-1])
        return dp[m][n]=solve(s,t,m-1,n-1,dp);
        
        int a=solve(s,t,m-1,n,dp);
        int b=solve(s,t,m,n-1,dp);
        
        return dp[m][n]=1+min(solve(s,t,m-1,n-1,dp),min(a,b));
        
        
        
    }
    int editDistance(string s, string t) {
        // Code here
        int m=s.length(), n=t.length();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solve(s,t,m,n,dp);
    }
    
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
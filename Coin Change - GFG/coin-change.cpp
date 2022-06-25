// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int solve(int S[],int m,int n,vector<vector<long long int>>& dp)
    {
        if(n==0)
        return dp[n][m]=1;
        
        if(n<0)
        return 0;
        
        if(m<0 and n>0)
        return 0;
        
        if(dp[n][m]!=-1)
        return dp[n][m];
        
        return dp[n][m]=solve(S,m-1,n,dp) + solve(S,m,n-S[m],dp);
        
    }
    
    long long int count(int S[], int m, int n) {

        // code here.
        vector<vector<long long int>> dp(n+1,vector<long long int>(m,-1));
        
        
        return solve(S,m-1,n,dp);
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends
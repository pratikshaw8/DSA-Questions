// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod=1e9+7;
    long long int solve(int h, vector<long> &dp)
    {
        if(h<=1)
        return 1;
        
        if(dp[h]!=-1) return dp[h];
        
        return dp[h] =(solve(h-1,dp) *( solve(h-1,dp)%mod + (2 * (solve(h-2,dp)%mod))%mod)%mod)%mod;
    }
    int tabulation(int h)
    {
        int mod=1e9+7;
        vector<long> dp(h+1,0);
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=h;i++)
        {
            dp[i]= (dp[i-1] *( (dp[i-1]%mod + (2* dp[i-2])%mod )%mod))%mod;
        }
        return dp[h];
    }
    long long int countBT(int h) { 
        // code here
        /*
        vector<long> dp(h+1,-1);
        int child=pow(2,h-1);
        return solve(h,dp);
        */
        
        return tabulation(h);
        
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends
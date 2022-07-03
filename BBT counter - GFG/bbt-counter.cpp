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
    long long int countBT(int h) { 
        // code here
        vector<long> dp(h+1,-1);
        int child=pow(2,h-1);
        return solve(h,dp);
        
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
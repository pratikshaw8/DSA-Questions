// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int mod=1e9+7;
    long long solve(int n,int k, vector<long long >& dp)
    {
        if(n==1)
        return k;
        if(n==2)
        return (k*k) %mod;
        if(dp[n]!=-1)
        return dp[n];
        
        return dp[n]=((k-1)*(solve(n-1,k,dp)%mod + solve(n-2,k,dp) %mod)%mod)%mod;
    }
    long long tabulation(int n,int k)
    {
        vector<long long> dp(n+1,0);
        long long prev2=k%mod;
        long long prev1=(k*k)%mod;

        for(int i=3;i<=n;i++)
        {
            long long ans=((k-1)* (prev1 +prev2)%mod)%mod;
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
    long long countWays(int n, int k){
        // code here
        // vector<long long > dp(n+1,-1);
        // return solve(n,k,dp);
        if(n==1)
        return k;
        return tabulation(n,k);
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends
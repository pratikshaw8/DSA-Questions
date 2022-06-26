// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int mod=1e9+7;
    long long int solveMem(int n,vector<long> &dp)
    {

        if(n==1 or n==2) return n;

        if(dp[n]!=-1)
        return dp[n];
        
        return dp[n]=( ((n-1)*solveMem(n-2,dp)%mod) +solveMem(n-1,dp)%mod  )%mod;
    }
    int tabulation(int n)
    {
        vector<long> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        
        for(int i=3;i<=n;i++)
        {
            long ans= (((i-1) * dp[i-2]%mod) +dp[i-1]%mod)%mod;
            dp[i]=ans;
        }
        return dp[n];
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        //  vector<long>dp(n+1,-1);
        //  return solveMem(n,dp);
         
        return tabulation(n)%mod;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends
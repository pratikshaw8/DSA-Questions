// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int solve(int n,int a[],int m,vector<vector<int>> &dp)
    {
        if(n==0)
        return 0;
        
        if(dp[n-1][m]!=-1) return dp[n-1][m];
        
        if(m > a[n-1] )
        return dp[n-1][m]=max(1+solve(n-1,a,a[n-1],dp),solve(n-1,a,m,dp));
        else
        return dp[n-1][m]=solve(n-1,a,m,dp);
    }
    
    int binSearch(int n, int a[])
    {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=INT_MIN;
        int ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int idx=upper_bound(dp.begin(),dp.end(),a[i])-dp.begin();
            if(dp[idx-1] <a[i] and dp[idx]>a[i] )
            {
                dp[idx]=a[i];
                ans=max(ans,idx);
            }
        }
        return ans;
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       
    //   int m=INT_MIN;
    //   for(int i=0;i<n;i++)
    //     m=max(m,a[i]);
    //   vector<vector<int>> dp(n+1,vector<int>(m+2,-1));
       
    //   return solve(n,a,m+1,dp);
    return binSearch(n,a);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends
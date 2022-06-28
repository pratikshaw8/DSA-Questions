// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{
    public:
    int solve(int n,int x,int y,int z,vector<int> &dp)
    {
        if(n==0)
        return 0;
        if(n<0)
        return INT_MIN;
        if(dp[n]!=-1) return dp[n];
        
        int a=solve(n-x,x,y,z,dp);
        int b=solve(n-y,x,y,z,dp);
        int c=solve(n-z,x,y,z,dp);
        
        return dp[n]=1+ max(a,max(b,c));
    }
    int tabulation(int n,int x,int y,int z)
    {
        vector<int> dp(n+1,INT_MIN);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            if(i-x>=0)
            dp[i]=max(dp[i],dp[i-x]+1);
            if(i-y>=0)
            dp[i]=max(dp[i],dp[i-y]+1);
            if(i-z>=0)
            dp[i]=max(dp[i],dp[i-z]+1);
        }
        return dp[n] < 0 ? 0:dp[n];
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int>dp(n+1,-1);
        return tabulation(n,x,y,z);
        int ans= solve(n,x,y,z,dp);
        if(ans<0 )
        return 0;
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
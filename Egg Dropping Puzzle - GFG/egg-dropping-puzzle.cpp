// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        // your code here
        int dp[n+1][k+1];
        memset(dp, 0, sizeof dp);
        
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(i==1)
                dp[i][j]=j;
                else if(j==1)
                dp[i][j]=1;
                else
                {
                    int mini=INT_MAX;
                    for(int l=1;l<=k;l++)
                    {
                        int a=max(dp[i][j-l],dp[i-1][l-1]);
                        mini=min(mini,a);
                    }
                    dp[i][j]=mini+1;
                }
            }
        }
        return dp[n][k];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
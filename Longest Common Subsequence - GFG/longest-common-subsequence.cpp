// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int solve(int x, int y, string s1, string s2,vector<vector<int>>& dp)
    {
        if(x==0 or y==0) return 0;
        
        if(dp[x][y]!=-1) return dp[x][y];
        
        if(s1[x-1] == s2[y-1])
        return dp[x][y]=1+ solve(x-1,y-1,s1,s2,dp) ;
        
        int a=solve(x-1,y,s1,s2,dp);
        int b=solve(x,y-1,s1,s2,dp);

        return dp[x][y]=max(a,b);
    }
    int tabulation(string s1, string s2)
    {
        int n=s1.size(),m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int spaceOpt(int x,int y,string s1,string s2)
    {
        int dp[2][y+1];
        
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                if(i==0 or j==0)
                dp[i%2][j]=0;
                else if(s1[i-1]== s2[j-1])
                dp[i%2][j]= 1+ dp[(i+1)%2][j-1];
                else
                {
                    dp[i%2][j]=max(dp[i%2][j-1],dp[(i+1)%2][j]);
                }
            }
        }
        return dp[x%2][y];
    }
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
       
        // int n=s1.size(),m=s2.size();
        //  vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        //  return tabulation(s1,s2);
        // return solve(n,m,s1,s2,dp);
        return spaceOpt(x,y,s1,s2);
    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
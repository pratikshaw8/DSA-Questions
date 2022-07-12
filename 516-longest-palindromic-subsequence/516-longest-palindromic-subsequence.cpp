class Solution {
public:
    int solve(string& s, int n, int i,int j,vector<vector<int>>& dp)
    {
        if(i>j)
            return 0;
        if(i==j)
            return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i] == s[j])
            return dp[i][j]=2+ solve(s,n,i+1,j-1,dp);
        else
        {
            return  dp[i][j]=max(solve(s,n,i+1,j,dp),solve(s,n,i,j-1,dp));
        }
    }
    int tabulation(string s)
    {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        
        for(int g=0; g<n;g++)
        {
            for(int i=0, j=g ; j<n; i++ , j++)
            {
                if(g==0)
                    dp[i][j]=1;
                else if(g==1)
                {
                    dp[i][j] = (s[i]==s[j]) ? 2:1;
                }
                else
                {
                    if(s[i] == s[j])
                        dp[i][j] = 2+ dp[i+1][j-1];
                    else
                        dp[i][j] =max(dp[i+1][j] ,dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
    int longestPalindromeSubseq(string s) {
        return tabulation(s);
        int n=s.length();
        if(n==1)
            return 1;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(s,n,0,n-1,dp);
    }
};
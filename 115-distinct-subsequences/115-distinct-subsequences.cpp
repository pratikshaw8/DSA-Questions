class Solution {
public:
    int mod=1e9+7;
    
    int tabulation(string s, string t)
    {
        int n=s.length(), m=t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                int exc=0,inc=0;
                exc= dp[i-1][j];
                if(s[i-1] == t[j-1])
                    inc=dp[i-1][j-1];
                dp[i][j]=(inc+exc)%mod;
            }
        }
        return dp[n][m];
    }
    int numDistinct(string s, string t) {
        return tabulation(s,t);
        
    }
};
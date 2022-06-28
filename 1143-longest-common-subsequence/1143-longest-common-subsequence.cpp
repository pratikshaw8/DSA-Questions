class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int x=text1.length();
        int y=text2.length();
        int dp[2][y+1];
        
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                if(i==0 or j==0)
                    dp[i%2][j]=0;
                else if(text1[i-1] == text2[j-1])
                {
                    dp[i%2][j]=1+ dp[(i+1)%2][j-1];
                }
                else
                {
                    dp[i%2][j]=max(dp[i%2][j-1],dp[(i+1)%2][j]);
                }
            }
        }
        return dp[x%2][y];
    }
};
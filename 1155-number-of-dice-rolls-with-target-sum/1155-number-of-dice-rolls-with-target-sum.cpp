class Solution {
public:
    
    int numRollsToTarget(int n, int k, int target) {
        
        int mod=1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(target+1 , 0));
        
        //analyze base case
        dp[0][0]=1;
        
        
        for(int dices =1 ; dices <=n ; dices++)
        {
            for(int x = 1; x<=target ; x++)
            {
                int ans=0;
                
                for(int i=1; i<=k;i++)
                {
                    if(x-i >=0)
                    ans = (ans+ dp[dices-1][x-i])%mod;
                }
                
                dp[dices][x] = ans;
            }
        }
        return dp[n][target];
    }
};
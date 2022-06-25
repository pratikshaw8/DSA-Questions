class Solution {
public:
    int  solve(vector<int>& coins, int n, vector<int>& dp)
    {
        if(n==0)
            return 0;
        
        if(n<0) return INT_MAX;
        
        int mini=INT_MAX;
        
        for(int i=0;i<coins.size();i++)
        {
            
            int ans=solve(coins,n-coins[i],dp);
            
            if(ans!=INT_MAX)
                mini=min(mini,1+ans);
        }
        dp[n]=mini;
        return mini;
    }
    int tabulation(vector<int>& coins, int amount)
    {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<coins.size();j++)
            {
                if(i-coins[j] >=0 and dp[i-coins[j]] != INT_MAX)
                {
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
                }
            }
        }
        if(dp[amount]==INT_MAX)
            return -1;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        
        // vector<int> dp(amount+1,INT_MAX);
        // int ans= solve(coins,amount,dp);
        // if(ans==INT_MAX)
        //     return -1;
        // return ans;
        return tabulation(coins,amount);
        
    }
};
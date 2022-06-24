class Solution {
public:
    int solve(vector<int>& cost, int i,vector<int>& dp) //top down function
    {
        if(i==0 or i==1)
            return cost[i];
        
        if(dp[i]!=-1)
            return dp[i];
        
        dp[i]=cost[i] + min(solve(cost,i-1,dp),solve(cost,i-2,dp));
        return dp[i];
        
    }
    int tabulation(vector<int>& cost,int n)
    {
        int prev1=cost[0];
        int prev2=cost[1];
        int ans=0;
        
        for(int i=2;i<n;i++)
        {
            ans=cost[i]+ min(prev1,prev2);
            prev1=prev2;
            prev2=ans;
            
        }
        return min(prev1,prev2);
        
            
    }
    int minCostClimbingStairs(vector<int>& cost) {
        
        //TOP DOWN
        // int n=cost.size();
        // vector<int> dp(n+1,-1);
        // int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        // return ans;
        
        
        //BOTTOM UP
        int n=cost.size();
        return tabulation(cost,n);
        
    }
};
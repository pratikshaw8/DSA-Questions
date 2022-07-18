class Solution {
public:
    
    int solve(vector<int>& obs, int lane,int i, vector<vector<int>> &dp)
    {
        
        if(i == obs.size()-1)
            return 0;
        
        if(dp[lane][i]!=-1) return dp[lane][i];
        
        if(obs[i+1] != lane)
            return solve(obs,lane,i+1,dp);
        else
        {
            int ans=INT_MAX;
            for(int l=1 ;l <=3;l++)
            {
                if(lane!=l and obs[i]!=l)
                {
                    ans=min(ans,solve(obs,l,i,dp) +1);
                }
            }
            return dp[lane][i]=ans;   
        }        
    }
    int minSideJumps(vector<int>& obstacles) {
        int n=obstacles.size();
        vector<vector<int>> dp(4,vector<int>(n,-1));
        return solve(obstacles , 2 , 0,dp);
    }
};
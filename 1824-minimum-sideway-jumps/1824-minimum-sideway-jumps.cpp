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
    int tabulation(vector<int> &obstacles)
    {
        int n=obstacles.size()-1;
        
        vector<int> curr(4,1e9);
        vector<int> next(4,1e9);
        next[0]=0;
        next[1]=0;
        next[2]=0;
        next[3]=0;
        

        for(int i=n-1;i>=0;i--)
        {
            for(int l=1;l<=3;l++)
            {
                if(obstacles[i+1]!=l)
                    curr[l] = next[l];
                else
                {
                     int ans=1e9;
                     for(int lane=1 ;lane <=3;lane++)
                     {
                         if(l!=lane and obstacles[i]!=lane)
                         {
                             ans=min(ans,next[lane] +1);
                         }
                         
                     }
                     curr[l]=ans;
                }
                
            }
            next=curr;
            
        }
        return min({ next[2] , next[1]+1 , next[3] +1});
    }
    int minSideJumps(vector<int>& obstacles) {
        return tabulation(obstacles);
        int n=obstacles.size();
        vector<vector<int>> dp(4,vector<int>(n,-1));
        return solve(obstacles , 2 , 0,dp);
    }
};
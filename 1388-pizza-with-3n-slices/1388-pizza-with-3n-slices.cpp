class Solution {
public:
    int solve(int stIdx, int endIdx, vector<int>&slices, int n, vector<vector<int>> &dp)
    {
        if(n==0 or stIdx > endIdx)
            return 0;
        
        if(dp[stIdx][n] != -1) return dp[stIdx][n];
        
        
        int take = slices[stIdx] + solve(stIdx+2, endIdx , slices , n-1 , dp);
        int notTake = 0 + solve(stIdx+1, endIdx, slices,n , dp );
        
        return dp[stIdx][n] = max(take,notTake);
    }
    int solveTab(vector<int>& slices)
    {
        int k=slices.size();
        
        vector<vector<int>> dp(k+2,vector<int>(k+2,0));        
        for(int index= k-2 ; index>=0 ; index--)
        {
            for(int n = 1 ; n <= k/3 ; n++)
            {
                int take = slices[index] + dp[index+2][n-1];
                int notTake = 0 + dp[index+1][n];
                
                dp[index][n] = max(take,notTake);
            }
        }
        int case1= dp[0][k/3];
        
        for(int i=0;i<k;i++)
        {
            fill(dp[i].begin() , dp[i].end() ,0);
        }
        
        for(int index= k-1 ; index>=1 ; index--)
        {
            for(int n = 1 ; n <= k/3 ; n++)
            {
                int take = slices[index] + dp[index+2][n-1];
                int notTake = 0 + dp[index+1][n];
                
                dp[index][n] = max(take,notTake);
            }
        }
        int case2= dp[1][k/3];
        
        return max(case1,case2);
        
    }
    int spaceOptimised(vector<int> &slices)
    {
        int k=slices.size();
        
        vector<int> prev(k+2,0);
        vector<int> curr(k+2,0);
        vector<int> next(k+2,0);
        
        for(int index= k-2 ; index>=0 ; index--)
        {
            for(int n = 1 ; n <= k/3 ; n++)
            {
                int take = slices[index] + next[n-1];
                int notTake = 0 + curr[n];
                
                prev[n] = max(take,notTake);
            }
            next=curr;
            curr=prev; 
            
        }
        int case1= prev[k/3];
        
        fill(prev.begin() , prev.end() ,0);
        fill(curr.begin() , curr.end() ,0);
        fill(next.begin() , next.end() ,0);
        
        for(int index= k-1 ; index>=1 ; index--)
        {
            for(int n = 1 ; n <= k/3 ; n++)
            {
                int take = slices[index] + next[n-1];
                int notTake = 0 + curr[n];
                
                prev[n] = max(take,notTake);
            }
            next=curr;
            curr=prev;
        }
        int case2= prev[k/3];
        
        return max(case1,case2);
    }
    
    int maxSizeSlices(vector<int>& slices) {
        /*
        int k=slices.size();
        int n=k/3;
        vector<vector<int>> dp(k,vector<int>(k,-1));
        
        int case1 = solve(0,k-2,slices,k/3,dp);
        
        for(int i=0;i<k;i++)
        {
            fill(dp[i].begin() , dp[i].end() ,-1);
        }
        int case2 = solve(1,k-1,slices,k/3,dp);
        
        return max(case1,case2);
        */
        
        return spaceOptimised(slices);
        
    }
};
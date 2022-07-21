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
    int maxSizeSlices(vector<int>& slices) {
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
    }
};
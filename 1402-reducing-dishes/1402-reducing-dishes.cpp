class Solution {
public:
    int solve(vector<int>& satisfaction, int idx, int val, vector<vector<int>>& dp)
    {
        if(idx == satisfaction.size())
        {
            return 0;
        }
        if(dp[idx][val]!=-1) return dp[idx][val];
        
        int exc = solve(satisfaction, idx+1, val ,dp);
        
        int inc = (satisfaction[idx] * val) + solve(satisfaction, idx+1, val+1,dp);
        
        return dp[idx][val] = max(inc,exc);
    }
    int tabulation(vector<int>& satisfaction)
    {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        
        
        int ans=0;
        
        for(int idx=0;idx<n;idx++)
        {
            int sum=0;
            int count=1;
            for(int j=idx ;j<n;j++)
            {
                sum+= satisfaction[j] * count;
                count++;
            }
            ans=max(sum,ans);
        }
        return ans;
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        
        return tabulation(satisfaction);
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        int ans = solve(satisfaction,0,1,dp);
        
        if(ans<0)
            return 0;
        return ans;
    }
};
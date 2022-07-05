class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n=days.size();
        int mod=1e9+7;
        vector<int> dp(n+1, INT_MAX);
        dp[n]=0;

        for(int i=n-1 ;i>=0;i--)
        {
            //for 1 day
            int way1 = cost[0] + dp[i+1];

            //for 7 days
            int j;
            for( j=i ; j<days.size() and days[j] < days[i]+7 ;j++);
            int way2=  cost[1] +dp[j];

            //for 30 days
            for( j=i ; j<days.size() and days[j] < days[i]+30 ;j++);
            int way3=  cost[2] +dp[j];

            dp[i]=min(way1, min( way2, way3));
        }
        return dp[0];
    }
};
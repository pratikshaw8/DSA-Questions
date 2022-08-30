class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> right(n);
        int maxi=0;
        for(int i=n-1;i>=0;i--)
        {
            maxi=max(maxi,prices[i]);
            right[i]  = maxi;
        }
        
        maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi = max(maxi, right[i] - prices[i]);
        }
        return maxi;
    }
};
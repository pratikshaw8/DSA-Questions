class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit=0;
        int n=prices.size();
        int min_price=prices[0];
        
        for(int i=1;i<n;i++)
        {
            if(prices[i] < min_price)
                min_price=prices[i];
            else
            {
                profit += prices[i] - min_price;
                min_price=prices[i];
            }
        }
        return profit;
    }
};
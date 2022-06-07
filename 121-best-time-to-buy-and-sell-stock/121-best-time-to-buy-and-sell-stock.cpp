class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        priority_queue<int> p;
        int n=prices.size();
        int maxi=INT_MIN;
        for(int i=n-1;i>=0;i--)
        {
            if(!p.empty())
            {
                if(p.top() -prices[i] >maxi)
                    maxi=p.top() - prices[i];
            }
            p.push(prices[i]);
        }
        if(maxi<0)
            return 0;
        return maxi;
    }
};
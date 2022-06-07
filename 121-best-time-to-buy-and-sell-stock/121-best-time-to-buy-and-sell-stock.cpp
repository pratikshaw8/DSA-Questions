class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int lsf=prices[0],op=0,pist=0;
        
        for(int i=0;i<prices.size();i++)
        {
            lsf=min(lsf,prices[i]);
            
            pist=prices[i]-lsf;
            
            op=max(pist,op);
        }
        return op;
    }
};
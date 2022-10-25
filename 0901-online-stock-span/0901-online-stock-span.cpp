class StockSpanner {
public:
    vector<pair<int,int>> s;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int a=1;
        if(s.empty())
        {
            s.push_back({price,1});
        }
        else
        {
            while(!s.empty()  and s.back().first <= price) 
            {
                a += s.back().second;
                s.pop_back();
            }
            s.push_back({price,a});
        }
        return a;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
class Solution {
public:
    int halveArray(vector<int>& nums) {        
        priority_queue<double> pq;
        double sum =0;
        for(auto x: nums)
        {
            pq.push((double)x);
            sum+=(double)x;
        }
        int c=0;
        
        double currSum=sum;
        
        while(currSum > sum/2)
        {
            double ele =pq.top();
            pq.pop();
            currSum -= ele/2;
            pq.push(ele/2);
            
            c++;
            
        }
        return c;
    }
};
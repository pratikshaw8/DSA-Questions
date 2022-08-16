class Solution {
public:
    bool check(vector<int> &nums, int mid, int threshold)
    {
        int sum=0;
        for(auto &val : nums)
        {
            sum+=ceil((double)val/mid);
        }
        return sum<= threshold;
        
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int i=1, j=*max_element(nums.begin() , nums.end()),ans=1;
        while(i<=j)
        {
            int mid = i+ (j-i)/2;
            
            if(check(nums,mid,threshold) )
            {
                ans=mid;
                j=mid-1;
            }
            else
                i=mid+1;
        }
        return ans;
    }
};
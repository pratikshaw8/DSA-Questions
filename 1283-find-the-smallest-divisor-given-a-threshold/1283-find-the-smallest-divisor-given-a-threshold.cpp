class Solution {
public:
    bool check(vector<int> nums, int i, int threshold)
    {
        int sum=0;
        for(int idx=0;idx<nums.size();idx++)
        {
            int r= nums[idx] % i ==0 ? nums[idx]/i : nums[idx]/i +1;
            sum += r;
        }
        if(sum<= threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int i=1, j=0;
        for(auto x: nums)
            j=max(j,x);
        
        int ans=0;
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
class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int mini = INT_MAX;
        int n=nums.size();
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            mini = min(mini,nums[mid]);
            
            if(nums[0] <= nums[mid])
            {
                if(nums[0] < nums[n-1])
                    return nums[0];
                
                    i=mid+1;
            }
            else
            {
                if(nums[0] > nums[n-1] and nums[n-2] > nums[n-1] )
                    return nums[n-1];
                j=mid-1;
            }
            
        }
        return mini;
    }
};
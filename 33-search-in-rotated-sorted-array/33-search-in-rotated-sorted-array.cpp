class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();
        int l=0,h=n-1;
        int mid;

        while(l<=h)
        {
            mid=(l+h)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[0]<=nums[mid])
            {
                if(nums[0]<=target && nums[mid]>target)
                    h=mid-1;
                else
                    l=mid+1;
            }
            else
            {
                if(target<=nums[n-1] && nums[mid]<target)
                    l=mid+1;
                else
                    h=mid-1;
            }
        }
        return -1;
        
    }
};
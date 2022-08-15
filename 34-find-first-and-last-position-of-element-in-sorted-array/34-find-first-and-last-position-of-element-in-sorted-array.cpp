class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=-1,second=-1;
        
        int i=0,j=nums.size()-1;
        
        while(i<=j)
        {
            int mid =i+ (j-i)/2;
            if(nums[mid] == target)
            {
                first = mid;
                second=mid;
                
                while(first-1>=0 and nums[first] == nums[first-1])
                    first--;
                
                while(second+1<nums.size() and nums[second] == nums[second+1])
                    second++;
                return{first,second};
            }
            else if(nums[mid] < target)
                i = mid+1;
            else
                j=mid-1;
        }
        return {-1,-1};
    }
};
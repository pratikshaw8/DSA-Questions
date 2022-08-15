class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int i=0,j=nums.size()-1;
        
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            
            if(mid >0 and nums[mid] < nums[mid-1])
                return nums[mid];
            else if(nums[mid] > nums[j])
                i=mid+1;
            else if(nums[mid] < nums[j])
                j--;
            else if(nums[i] == nums[mid] and mid!=i)
                i++;
            else
                j=mid-1;
            
        }
        return nums[i];
    }
};
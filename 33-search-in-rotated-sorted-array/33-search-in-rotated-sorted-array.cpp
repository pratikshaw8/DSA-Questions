class Solution {
public:
    int getPivot(vector<int>& nums)
    {
        int n=nums.size();
        int i = 0, j = n - 1;

        while (i < j)
        {
            int mid = i + (j - i) / 2;
            if (nums[mid] >= nums[0])
                i = mid + 1;
            else
                j = mid;
        }
        return i;
    }
    int binSearch(vector<int>& nums, int target ,int s,int e)
    {
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if(nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                s = mid + 1;
            else
                e = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        
        int pivot=getPivot(nums);
        int n=nums.size();
        
        if(nums[pivot] <=target and target <= nums[n-1])
        {
            return binSearch(nums,target,pivot,n-1 );
        }
        else
        {
            return binSearch(nums,target,0,pivot-1 );
        }
        
    }
};
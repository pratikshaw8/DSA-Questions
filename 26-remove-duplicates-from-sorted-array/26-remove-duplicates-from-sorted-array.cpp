class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k=1;
        int prev=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(prev == nums[i])
            {
                continue;
            }
            prev=nums[i];
            swap(nums[k++],nums[i]);
            
        }
        return k;
    }
};
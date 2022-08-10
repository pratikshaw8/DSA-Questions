class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int ma= nums[0];
        int count=1;
        for(int i=0;i<nums.size();i++)
        {
            if(ma == nums[i])
                count++;
            else
                count--;
            if(count==0)
            {
                count=1;
                ma=nums[i];
            }
        }
        count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == ma)
                count++;
        }
        if(count>nums.size()/2)
            return ma;
        return -1;
    }
};
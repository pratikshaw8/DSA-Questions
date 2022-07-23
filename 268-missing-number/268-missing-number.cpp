class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int ans=0;
        int i=0;
        
        for(i=0;i<nums.size();i++)
        {
            ans= ans xor nums[i];
            ans=ans xor i+1;
        }
        return ans;
    }
};
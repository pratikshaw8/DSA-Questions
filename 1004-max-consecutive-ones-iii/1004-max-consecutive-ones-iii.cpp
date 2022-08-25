class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ones=0,ans=0;
        
        int i=0,j=0;
        while(j<nums.size())
        {
            if(nums[j] == 1)
                ones++;
            
            if( j-i+1-ones <= k)
                ans=max(ans,j-i+1);
            else
            {
                while(k < j-i+1-ones)
                {
                    if(nums[i] == 1)
                        ones--;
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};
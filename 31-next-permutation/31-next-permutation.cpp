class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i,j,n=nums.size();
        for(i=n-1;i>=1;i--)
        {
            if(nums[i-1] < nums[i])
            {
                for(j=i;j<n;j++)
                {
                    if(nums[i-1] >= nums[j])
                    {
                        j--;
                        break;
                    }
                }
                if(j>=n)
                    j--;
                swap(nums[i-1],nums[j]);
                break;
                
            }
        }
        
        sort( nums.begin()+i,nums.end());
        
        
        
        
    }
};
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int i=0,j=0;
        int ans=0;
        int prod=1;
        int n=nums.size();
        while(j<n)
        {
            prod *= nums[j];
            
            while(i<=j and prod >=k)
            {
                prod=prod/nums[i];
                i++;
            }
            ans+= (j-i+1);
            j++;
        }
        return ans;
    }
};
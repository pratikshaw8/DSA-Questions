class Solution {
public:
    int solve(vector<int> &nums,int n,int j)
    {
        int prev2=0;
        int prev1=nums[j];
        
        for(int i=j+1;i<n;i++)
        {
            int inc=prev2+nums[i];
            int exc=prev1;
            int ans=max(exc,inc);
            
            prev2=prev1;
            prev1=ans;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        return max(solve(nums,n-1,0),solve(nums,n,1));
    }
};
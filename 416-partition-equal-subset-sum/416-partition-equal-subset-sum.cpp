class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=nums[i];
            
        if(sum %2 ==1) return 0;
        sum=sum/2;
        
        
        vector<int> curr(sum+1,0);
        vector<int> prev(sum+1,0);
        
        for(int i=0;i<=n;i++)
            prev[0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(nums[i-1] <= j)
                curr[j]= prev[j-nums[i-1]] or prev[j];
                else
                curr[j]=prev[j];
            }
            prev=curr;
        }
        return curr[sum];
    }
};
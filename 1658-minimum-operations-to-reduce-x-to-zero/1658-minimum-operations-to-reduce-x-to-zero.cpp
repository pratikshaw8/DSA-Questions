class Solution {
public:
    
    int minOperations(vector<int>& nums, int x) {
        
        int tar=accumulate(nums.begin(),nums.end(),0) -x;
        if(tar < 0)
             return -1;
        
        long long sum=0;
        int res=-1;
        
        for(int i=0,j=0 ; j<nums.size() ; j++)
        {
            sum+=nums[j];
            
            while(sum> tar)
            {
                sum-=nums[i];
                i++;
            }
            
            if(sum == tar)
                res=max(res, j-i+1);
        }
        return res == -1 ? -1 : nums.size() - res;
    }
};
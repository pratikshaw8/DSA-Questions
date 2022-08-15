class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int closeSum=INT_MAX;
        
        sort(nums.begin() , nums.end());
        
        for(int i=0;i<nums.size() -2 ;i++)
        {
            int j=i+1,k=nums.size()-1;
            while(j<k)
            {
                int sum= nums[i] +nums[j] +nums[k];
                
                if(sum==target)
                    return sum;
                else if(sum < target)
                    j++;
                else
                    k--;
                
                if(closeSum==INT_MAX or abs(sum-target) < abs(closeSum-target))
                    closeSum=sum;
            }
        }
        return closeSum;
    }
};
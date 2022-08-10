class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int count1=0,count2=0;
        
        int first=1e9+7;
        int second=1e9+7;
        
        for(int i=0;i<nums.size();i++)
        {
            if(first == nums[i])
                count1++;
            else if(second == nums[i])
                count2++;
            else if(count1==0)
            {
                count1=1;
                first=nums[i];
            }
            else if(count2==0)
            {
                count2=0;
                second=nums[i];
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int i=0;i<nums.size() ;i++)
        {
            if(nums[i] == first)
                count1++;
            else if(nums[i] == second)
                count2++;
        }
        vector<int> ans;
        if(count1 >nums.size()/3)
            ans.push_back(first);
        if(count2 > nums.size()/3)
            ans.push_back(second);
        return ans;
            
    }
};
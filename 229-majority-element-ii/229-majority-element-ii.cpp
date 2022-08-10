class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int count=1;
        int first=1e9+7;
        int second=1e9+7;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1] == nums[i])
                count++;
            else
            {
                if(count > nums.size()/3)
                {
                    if(first==1e9+7)
                    {
                        first = nums[i-1];
                    }
                    else
                        second = nums[i-1];
                }
                
                count=1;
            }
        }
        if(count > nums.size()/3)
                {
                    if(first==1e9+7)
                    {
                        first = nums[nums.size()-1];
                    }
                    else
                        second = nums[nums.size()-1];
                }
        
        if(first==1e9+7)
            return {};
        else if(second ==1e9+7)
            return {first};
        return {first,second};
            
    }
};
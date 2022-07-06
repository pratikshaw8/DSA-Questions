class Solution {
public:
    
    vector<int> rearrangeArray(vector<int>& nums) {
       
        vector<int> v;
        
        int i=0,j=0,flag=1;
        
        while(v.size() != nums.size())
        {
            if(flag==1)
            {
                if(nums[i] >0)
                {
                    v.push_back(nums[i]);
                    flag=-1;
                }
                i++;
            }
            else
            {
                if(nums[j]<0)
                {
                    v.push_back(nums[j]);
                    flag=1;
                }
                j++;
            }
        }
        return v;
        
        
    }
};
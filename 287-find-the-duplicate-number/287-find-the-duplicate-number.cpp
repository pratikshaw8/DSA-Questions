class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
         for(int i=0;i<nums.size();i++)
         {
             
             int curr=abs(nums[i]);
             
             if(nums[curr]<0)
                 return curr;
             nums[curr]*=-1;
         }
         return -1;
    }
};
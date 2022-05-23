class Solution {
public:
    
    void solve(vector<vector<int>>& ans,vector<int>& nums,vector<int> temp, int index)
    {
        if(index==nums.size())
        {
            vector<int>temp=nums;
            
            if(find(ans.begin(),ans.end(),temp) == ans.end())
                ans.push_back(temp);
            return;
        }
        
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[index],nums[i]);
            solve(ans,nums,temp,index+1);
            swap(nums[index],nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>temp;
        
        
        
        solve(ans,nums,temp,0);
        return ans;
    }
};
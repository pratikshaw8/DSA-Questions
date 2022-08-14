class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        set<vector<int>> st;
        for(int i=0 ; i<nums.size()-1 ; i++)
        {
            int l=i+1,r=nums.size()-1;
            
            while(l<r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    st.insert({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(sum<0) l++;
                else
                    r--;
                
            }
        }
        for(auto i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
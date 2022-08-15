class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int ans=0;
        int sum=0;
        mp[sum]=1;
        for(auto i:nums)
        {
            sum+= i;
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;
    }
};
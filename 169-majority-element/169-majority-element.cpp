class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        map<int,int> m;
        for(auto i:nums)
        {
            m[i]++;
        }
        
        for(auto i:m)
        {
            if(i.second > n/2)
                return i.first;
        }
        return 0;
    }
};
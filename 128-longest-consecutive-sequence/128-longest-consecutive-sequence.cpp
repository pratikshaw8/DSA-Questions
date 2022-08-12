class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        int maxi=0;
        int count=0;
        
        for(int i=0 ;i <nums.size() ;i++)
        {
            if(s.find(nums[i]) == s.end())
            s.insert(nums[i]);
        }
        
        int prev=-1e9+7;
        for(auto x: s)
        {
            if(prev == -1e9+7 or x -1 == prev){
                count++;
                prev=x;
            }
            else{
                maxi=max(maxi,count);
                count=1;
                prev=x;
            }
        }
        maxi=max(maxi,count);
        return maxi;
    }
};
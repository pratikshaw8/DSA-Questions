class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]=true;
        }
        
        int ans=0,c=1;
        
        while(ans< mp.size())
        {
            auto it=mp.begin();
            int  x= it->first , y=x-1; c=0;
            while(true)
            {
                if(mp.find(y) == mp.end()) break;
                c++;
                mp.erase(y);
                y--;
            }
            
            while(true)
            {
                if(mp.find(x) == mp.end()) break;
                c++;
                mp.erase(x);
                x++;
            }
            ans=max(ans,c);
        }
        return ans;
    }
};
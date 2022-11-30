class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        
        for(auto x: arr)
        {
            mp[x]++;
        }
        
        unordered_map<int,int> m;
        
        for(auto x:mp)
        {
            if(m.find(x.second) != m.end())
                return false;
            else
            {
                m[x.second]++;
            }
        }
        return true;
        
        
    }
};
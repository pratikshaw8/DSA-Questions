class Solution {
public:
    
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        for(auto x: s)
        {
            mp[x]++;
        }
        string ans;
        
        vector<vector<char>> bucket(n+1);
        
        for(auto [c,f] : mp)
        {
            bucket[f].push_back(c);
        }
        
        for(int freq= n ; freq>=1 ; freq--)
        {
            for(char c: bucket[freq])
            {
                ans.append(freq,c);
            }
        }
        return ans;
    }
};
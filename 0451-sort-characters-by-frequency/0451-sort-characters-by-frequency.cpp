class Solution {
public:
    
    string frequencySort(string s) {
        map<char,int> mp;
        
        for(auto x: s)
        {
            mp[x]++;
        }
        string ans;
        
        multimap<int, char> MM;
  
    
        for (auto& it : mp) {
            MM.insert({ it.second, it.first });
        }
  
        
        for(auto x:MM)
        {
            ans.append(x.first,x.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
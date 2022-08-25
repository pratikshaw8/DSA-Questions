class Solution {
public:
    bool check(unordered_map<char,int> &m , unordered_map<char,int> &mp)
    {
        for(auto x: mp)
        {
            if(m.find(x.first) == m.end() or m[x.first] < x.second)
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        for(char ch:t)
        {
            mp[ch]++;
        }
        
        int ans=INT_MAX;
        string res="";
        
        unordered_map<char,int> m;
        int i=0,j=0;
        
        while(j<s.length())
        {
            m[s[j]]++;
            
            
            while(!m.empty() and  check(m,mp) )
            {
                if(ans > j - i +1)
                {
                    ans=j-i+1;
                    res=s.substr(i,j-i+1);
                }
                m[s[i]]--;
                if(m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
            
            j++;
            
        } 
        
        return res;
    }
};
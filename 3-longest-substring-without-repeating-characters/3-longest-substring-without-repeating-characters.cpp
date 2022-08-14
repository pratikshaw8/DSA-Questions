class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s=="")
            return 0;
        
        unordered_map<char,bool> mp;
        int maxi=1;
        mp[s[0]]=true;
        
        
        for(int i=1;i<s.length();i++)
        {
            if(mp.find(s[i]) != mp.end() )
            {
                int size=mp.size();
                maxi=max(maxi,size);
                int j=i-size;
                do
                {
                    
                    mp.erase(s[j]);
                    if(s[j] == s[i])
                        break;
                    j++;
                }while(j<i and !mp.empty());
                
            }
            mp[s[i]]=true;
        
        }
        int size=mp.size();
        maxi=max(maxi,size);
        
        return maxi;
            
    }
};